/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there 
is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square 
with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

class Solution {
public:
    int DFS(vector<vector<int>>& grid,int x, int y,vector<vector<bool>>&visited){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||!grid[x][y])return 1;
        if(visited[x][y])return 0;
        visited[x][y] = true;
        int a = DFS(grid,x+1,y,visited);
            a +=DFS(grid,x-1,y,visited);
            a +=DFS(grid,x,y+1,visited);
            a +=DFS(grid,x,y-1,visited);
        return a;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]){
                    return DFS(grid,i,j,visited);
                }
            }
        }
        return 0;
    }
};
