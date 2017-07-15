/*
Question# + Difficulty + Topic + Company + Similar_Question
[174] [Dungeon Game] [Hard] [Binary Search Dynamic Programming ] 
[Microsoft] 
[62 64].cpp
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if(i == m- 1 && j != n-1)
                    /* if need >0, then use need, otherwise, we need minimum 1*/
                    grid[i][j] = (-grid[i][j] +  grid[i][j + 1])>0? 
                                    (-grid[i][j] +  grid[i][j + 1]):1;
                
                else if(j == n-1 && i != m-1)
                    grid[i][j] = (-grid[i][j] + grid[i + 1][j])>0?
                                    (-grid[i][j] + grid[i + 1][j]):1 ;
                
                else if(j != n- 1 && i != m-1)
                    grid[i][j] = (-grid[i][j] + min(grid[i + 1][j],grid[i][j + 1]))>0?
                                    (-grid[i][j] + min(grid[i + 1][j],grid[i][j + 1])):1;
                
                else if(j == n- 1 && i == m-1) grid[i][j] = (-grid[i][j]>0)?
                                                                -grid[i][j]+1:1;
            }
        }
        return grid[0][0];
    }
};
