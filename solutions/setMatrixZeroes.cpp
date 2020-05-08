//Solution 1: Using Sets
//Time Complexity O(m * n)
//Space Complexity O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //vaariables for row and column
        int r = matrix.size();
        int c = matrix[0].size();
        
        //sets to store rows and columns that have a 0 
        set<int> rows;
        set<int> cols;
        
        //go through matrix
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                //if the value is 0 
                //add the row and column to the sets
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                } 
            }
        }
        
        //Go through matrix again
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                //if either the row or column is in the sets
                //change that point to 0
                if(rows.find(i) != rows.end() || cols.find(j) != cols.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//Solution 2: Simulation
//Time Complexity O(n * m)
//Space Complexity O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Idea is to use first row/column to flag if others need 0s
        //NOTE the order in which you do all of this matters
        //You have to do the two if statements last and the row has to go first

        //variables for row and column
        int r = matrix.size();
        int c = matrix[0].size();
        
        //bool to know if we need to change first column to 0
        bool firstColumnZero = false;
        
        //go through all rows (because we need to check first columns as well for bool)
        for(int i = 0; i < r; ++i){
            //if any first column is = change the bool to true
            if(matrix[i][0] == 0) firstColumnZero = true;
            //we could go through all columns but only need to start from 1 
            //because we are updating and it would be redundant
            for(int j = 1; j < c; ++j){
                //if that index is 0
                if(matrix[i][j] == 0){
                    //update the beginning row and column
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //we want to go through everything except outer row and column
        for(int i = 1; i < r; ++i){
            for(int j = 1; j < c; ++j){
                //if either of them are 0 make the index 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        //then we want to check first row
        //at this point if anything from first row is 0, the origin is 0 too
        //we can start from 1 since 0,0 is already 0. 
        //set everything in first row to 0 if it is true
        if(matrix[0][0] == 0){
            for(int j = 1; j < c; ++j) matrix[0][j] = 0;
        }
        
        //if first column is true
        //set everything in first column to 0
        if(firstColumnZero){
            for(int i = 0; i < r; ++i) matrix[i][0] = 0;
        }
    }
};