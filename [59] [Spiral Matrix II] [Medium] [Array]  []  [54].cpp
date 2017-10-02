/*
Question# + Difficulty + Topic + Company + Similar_Question
[59] [Spiral Matrix II] [Medium] [Array] 
[] 
[54].cpp
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(!n) return {};
        vector<vector<int>> res(n,vector<int>(n,0));
        int count = 1;
        int up = 0,right = n-1,down = n-1,left = 0;
        while(1)
        {
            for(int col=left;col<=right;col++)res[up][col]=count++;
            if(++up>down)break;
            
            for(int row = up;row<=down;row++)res[row][right]=count++;
            if(--right<left)break;
            
            for(int col = right;col>=left;col--)res[down][col]=count++;
            if(--down<up)break;
            
            for(int row=down;row>=up;row--)res[row][left]=count++;
            if(++left>right)break;
        }
        
        return res;
    }
};
