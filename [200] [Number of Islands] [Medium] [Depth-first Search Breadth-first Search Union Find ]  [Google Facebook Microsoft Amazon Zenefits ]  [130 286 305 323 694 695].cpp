/*
Question# + Difficulty + Topic + Company + Similar_Question
[200] [Number of Islands] [Medium] [Depth-first Search Breadth-first Search Union Find ] 
[Google Facebook Microsoft Amazon Zenefits ] 
[130 286 305 323 694 695].cpp
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        stack<pair<int,int>> sta;
        for(int row = 0;row<grid.size();row++)
        {
            for(int col = 0;col<grid[0].size();col++)
            {
                if(grid[row][col]!='1') continue;
                sta.push(pair<int,int>(row,col));
                while(!sta.empty())
                {
                    pair<int,int> pos=sta.top();
                    sta.pop();
                    int row = pos.first;int col = pos.second;
                    //if(grid[row][col]!='1') cout<<"POP Water! Shouldn't Happen"<<endl;
                    grid[row][col] = '0';

                    //successor
                    if(row+1<grid.size()&&grid[row+1][col]=='1') sta.push(pair<int,int>(row+1,col));
                    if(row-1>=0&&grid[row-1][col]=='1') sta.push(pair<int,int>(row-1,col));
                    if(col+1<grid[0].size()&&grid[row][col+1]=='1') sta.push(pair<int,int>(row,col+1));
                    if(col-1>=0&&grid[row][col-1]=='1') sta.push(pair<int,int>(row,col-1));
                }
                count++;
            }
        }
        return count;
    }
};
