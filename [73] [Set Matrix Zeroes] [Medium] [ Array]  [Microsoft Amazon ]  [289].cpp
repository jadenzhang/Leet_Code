/*
Question# + Difficulty + Topic + Company + Similar_Question
[73] [Set Matrix Zeroes] [Medium] [ Array] 
[Microsoft Amazon ] 
[289].cpp
*/


/*It's Easy for O(mn) or Even O(m+n) Extra space, the trick of O(1) is to store flag inside
  Only [0][0] might conflict for it's the place both row column store flag*/
  
  
  
  class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag = 1,m = matrix.size(),n = matrix[0].size();
        if(!m ||!n) return;
        
        for(int row =0;row<m;row++)
        {
            if(matrix[row][0]==0) flag=0;
            for(int col = 1;col<n;col++)
            {
                if(matrix[row][col]==0) matrix[row][0] = matrix[0][col]=0;
            }
        }
        
        for(int row = m-1;row>=0;row--)
        {
            for(int col = n-1;col>=1;col--)
            {
                if(matrix[row][0]==0|| matrix[0][col]==0) matrix[row][col] = 0;
            }
            if(flag==0) matrix[row][0]=0;
        }
    }
};
