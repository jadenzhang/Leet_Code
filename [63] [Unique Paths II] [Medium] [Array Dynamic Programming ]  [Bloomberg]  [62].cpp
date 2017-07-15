/*
Question# + Difficulty + Topic + Company + Similar_Question
[63] [Unique Paths II] [Medium] [Array Dynamic Programming ] 
[Bloomberg] 
[62].cpp
*/


/* Improved efficiency version, it return 0 directly if a single column block the way */
/* Eg  0 1 0 0 
       0 1 0 0
       0 1 0 0
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) 
    {
        int m = a.size();
        if(m==0) return 0;
        int n = a[0].size();
        bool flag;
        
        for(int i=0; i<m; i++)
        {   flag=0;
             for(int j=0; j<n; j++)
             {
                int left = (j==0) ? 0 : a[i][j-1];
                int top = (i==0) ? 0: a[i-1][j];
                if(i==0 && j==0 && a[i][j]==0)a[i][j]=1;  // to make the first box  1
                else a[i][j] = a[i][j]==1 ? 0 : left+top; //update a[i][j] to the no of paths to a[i][j]
                if(a[i][j]>0) flag=1; 
             }
                if(!flag) return 0;
        }
        return a[m-1][n-1];
        
    }
}; 
