/*
Question# + Difficulty + Topic + Company + Similar_Question
[79] [Word Search] [Medium] [Array Backtracking ] 
[Facebook Microsoft Bloomberg  ] 
[212].cpp
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n=board[0].size(),length = word.size();
        for(int row = 0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(recur(board,word,row,col,0)) return true;
            }
        }
        return false;
    }
    
    bool recur(vector<vector<char>>& board, string word, int row, int col, int cur)
    {
        int m = board.size(),n=board[0].size(),length = word.size();
        if(cur>=length) return true;
        if(row<0|| row>=m || col<0|| col>=n) return false;
        
        if(board[row][col]==word[cur])
        {
            char ch = board[row][col];
            //To Prevent circle, we mark used position
            board[row][col]='0';
            bool flag = recur(board,word,row+1,col,cur+1)||recur(board,word,row-1,col,cur+1)
                        ||recur(board,word,row,col+1,cur+1)||recur(board,word,row,col-1,cur+1);
            board[row][col]=ch;
            return flag;
        }
        return false;
    }
};
