/*
Question# + Difficulty + Topic + Company + Similar_Question
[64] [Minimum Path Sum] [Medium] [Array Dynamic Programming ] 
[] 
[62 174].cpp
*/

//\mathrm{grid}(i, j)=\mathrm{grid}(i,j)+\min \big(\mathrm{grid}(i+1,j), \mathrm{grid}(i,j+1)\big) grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if(i == m- 1 && j != n-1)
                    grid[i][j] = grid[i][j] +  grid[i][j + 1];
                else if(j == n-1 && i != m-1)
                    grid[i][j] = grid[i][j] + grid[i + 1][j];
                else if(j != n- 1 && i != m-1)
                    grid[i][j] = grid[i][j] + min(grid[i + 1][j],grid[i][j + 1]);
            }
        }
        return grid[0][0];
        
    }
};
