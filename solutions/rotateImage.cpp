//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        //first we want to transpose matrix
        //this means swap [i][j] with [j][i]
        for(int i = 0; i < r; ++i){
            //inportant to start at j = i so we want swap too many times
            for(int j = i; j < c; ++j){
                swap(matrix[i][j], matrix[j][i]);
                //Here is how to do swap without function
                //int temp = matrix[i][j];
                //matrix[i][j] = matrix[j][i];
                //matrix[j][i] = temp;
            }
        }
        
        //then we want to reverse each row
        for(auto &v: matrix){
            reverse(v.begin(), v.end());
        }

        //another way to write the reverse function above
        //for(int i = 0; i < r; ++i){
             //for(int j = 0; j < c / 2; ++j){
                //int temp = matrix[i][j];
                //matrix[i][j] = matrix[i][c - 1 - j];
                //matrix[i][c - 1 - j] = matrix[i][j];
            //}
        //}
    }
};