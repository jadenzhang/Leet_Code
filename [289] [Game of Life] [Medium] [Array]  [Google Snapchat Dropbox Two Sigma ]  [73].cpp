/*
Question# + Difficulty + Topic + Company + Similar_Question
[289] [Game of Life] [Medium] [Array] 
[Google Snapchat Dropbox Two Sigma ] 
[73].cpp
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //The Trick is how to represent both state in-place
        //It can be solved by encoding four kind of combined state
        /*
            0: death 1: live
            0 0 -> death to death == 0
            0 1 -> death to live  == 1
            1 0 -> live to death  == 2
            1 1 -> live to live   == 3
        */
        int m = board.size(),n = board[0].size();
        
        int block[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        
        for(int row = 0;row<m;row++)
        {
            for(int col = 0;col<n;col++)
            {
                /*count live num*/
                int count = 0;
                for(int i = 0;i<8;i++)
                {
                    int x = block[i][0]+row;
                    int y = block[i][1]+col;
                    if(x<0||x>=m||y<0||y>=n) continue;
                    if((x==row&&y>col)||(x>row))//state not altered yet, 0 or 1
                    {
                        //cout<<"Ahead "<<"at:["<<x<<","<<y<<"]";
                        if(board[x][y]==1) {count++;cout<<" yes"<<endl;}
                    }
                    else//state already changed to multi-state
                    {
                        //cout<<"Prev "<<"at:["<<x<<","<<y<<"]";
                        if(board[x][y]>1){count++;cout<<" yes"<<endl;}
                    }           
                }
                
                
                /*transition*/
                
                //currently dead
                if(board[row][col]==0)
                {
                    board[row][col]=(count==3)? 1:0;//dead to live only count==3
                }
                //currently live
                else                 
                {
                    board[row][col] = (count<2||count>3)? 2:3;//live to death when count<2 or count>3
                }
                //cout<<"at:["<<row<<","<<col<<"]"<<"count: "<<count<<" state:"<<board[row][col]<<endl;
            }
        }
        // Trim our multi-state to single
        for(int row = 0; row < m; row++)
        {
            for(int col=0; col < n; col++)
            {
                board[row][col] &=1;//&=1 will only take LSB
            }
        }
    }
};
