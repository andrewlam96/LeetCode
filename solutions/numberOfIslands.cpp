//Solution 1: DFS
//Time Complexity O(m * n)
//Space Complexity O(m * n)
class Solution {
    void dfs(vector<vector<char>> &grid, int r, int c){
        //get row and column
        int row = grid.size();
        int col = grid[0].size();
        
        //change the node to '0' to mark it as visited
        grid[r][c] = '0';

        //these basically go in each direction
        //so we check if the index is in bounds and if that index point is '1'
        //if it is, we recursively call the function
        if(r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
        if(r + 1 < row && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if(c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
        if(c + 1 < col && grid[r][c+1] == '1') dfs(grid, r, c+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        //get row and column 
        //if it is empty return 0
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        int islands = 0; //count islands

        //go through the row and column
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                //if a node is '1' that means it's a start to an island
                //NOTE that islands do not circle around so the four corners of a grid no not connect
                if(grid[i][j] == '1'){
                    ++islands; //we increment the counter
                    dfs(grid, i, j); //and call our dfs helper function
                }
            }
        }
        return islands;
    }
};