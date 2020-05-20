//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
    void dfs(vector<vector<int>> &image, int r, int c, int color, int newColor){
        //if the position we are in is the color we want
        if(image[r][c] == color){
            //change it to it's new color
            image[r][c] = newColor;

            //then we will try to check the 4 directions (within bounds)
            if(r >= 1) dfs(image, r-1, c, color, newColor);
            if(c >= 1) dfs(image, r, c-1, color, newColor);
            if(r+1 < image.size()) dfs(image, r+1, c, color, newColor);
            if(c+1 < image[0].size()) dfs(image, r, c+1, color, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        //if the color is not the newcolor we want to change any of the same color is the 4 directions to the new color
        if(color != newColor) dfs(image, sr, sc, color, newColor);
        return image;
    }
};