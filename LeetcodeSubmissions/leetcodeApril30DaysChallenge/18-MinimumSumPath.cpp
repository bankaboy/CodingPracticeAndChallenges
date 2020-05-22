/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

/* Solution 1 - dfs - exceeded time limit
Since a move can be only towards right or down.
1. If grid is a single cell , return it.
2. For every element, return the minimum out of down move total cost and right move total cost.
*/

class Solution {
public: 
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
 
        if(i<grid.size()-1 && j<grid[0].size()-1){
            int r1 = grid[i][j] + dfs(i+1, j, grid);
            int r2 = grid[i][j] + dfs(i, j+1, grid);
            return min(r1,r2);
        }
 
        if(i<grid.size()-1){
            return grid[i][j] + dfs(i+1, j, grid);
        }
 
        if(j<grid[0].size()-1){
            return grid[i][j] + dfs(i, j+1, grid);
        }
 
        return 0;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        return dfs(0,0,grid);
    }
};

/* Solution 2 - Dynamic Programming
Fill up cost table by only right moves from start(only top row).
Fill up cost table by only down moves from start(only left column).
For every element in grid from first row onwards:
    1. compute cost of move from upper cell(down move) and left cell(right move).
    2. Compare them - 
    3. If cost of move from left cell is less, set cost of that position to sum of cost of left cell and element in grid at that position.
    4. If cost of move from upper cell is less, set cost of that position to sum of cost of upper cell and element in grid at that position.
Return the cost in the bottom right element of cost table.
*/
class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)
        return 0;
 
        int m = grid.size();
        int n = grid[0].size();
 
        int dp[m][n];
        dp[0][0] = grid[0][0];    
 
        // initialize top row
        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
 
        // initialize left column
        for(int j=1; j<m; j++){
            dp[j][0] = dp[j-1][0] + grid[j][0];
        }
 
        // fill up the dp table
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }else{
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            }
        }
 
        return dp[m-1][n-1];
    }
};
