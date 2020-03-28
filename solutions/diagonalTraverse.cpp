class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        //if empty return an empty vector
        if(matrix.size() == 0) return vector<int>();
        
        //variables to represent the row and column size
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> solution; //vector to store the answer
        vector<int> temp; //vector to get each diagonal before putting in solution
        
        for(int i = 0; i < n + m - 1; ++i){ //there will be n + m - 1 diagonals
            temp.clear(); //make sure to empty out old diagonal

            //each diagonal is top down
            //row is going to be 0 until it reaches the end. 
            //then it will move down one which can be the max of first row (i) - total columns + 1
            int row = i < m ? 0 : i - m + 1;
            
            //column will be i since that is incrementing by 1 everytime until it reaches end of row
            //then it will be m - 1 to be end of the column 
            int column = i < m ? i : m - 1;
            
            //while loop keeps the diagonal inbounds where row < max row and column is not negative
            while(row < n && column > -1){
                temp.push_back(matrix[row][column]);
                ++row; //move down a row
                --column; //move left a column
            }
            
            //since we want it diagonally, every 2nd diagonal should be flipped
            if(i % 2 == 0){
                reverse(temp.begin(), temp.end());
            }
            
            //insert into solutions vector
            for(int j = 0; j < temp.size(); ++j){
                solution.push_back(temp[j]);
            }
        }
        return solution;
    }
};