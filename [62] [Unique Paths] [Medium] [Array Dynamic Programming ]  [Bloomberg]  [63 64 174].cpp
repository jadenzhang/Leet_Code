/*
Question# + Difficulty + Topic + Company + Similar_Question
[62] [Unique Paths] [Medium] [Array Dynamic Programming ] 
[Bloomberg] 
[63 64 174].cpp
*/


/× Use DP that each block have # ways = # ways on top + # ways on left */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int ary[m][n];
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                ary[i][j] = i+j==0? 1:0;
                ary[i][j]+= i-1>=0? ary[i-1][j]:0;
                ary[i][j]+= j-1>=0? ary[i][j-1]:0;
                //cout<<"at i: "<<i<<" and j: "<<j<<" ways: "<<ary[i][j]<<endl;
            }
        }
        return ary[m-1][n-1];
    }
};
