//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> solution;
        if(matrix.size() == 0) return solution;
        
        //variables for row and column size
        int row = matrix.size(), col = matrix[0].size();
        
        //4 variables to indicate the bounds of matrix
        int left = 0, right = col - 1, top = 0, bottom = row - 1;

        //4 bools to indicate which direction to go (true means traverse that direction)
        //assumption that we start at top and go left to right at first in clockwise spiral
        bool leftToRight = true, topToBottom = false,
             rightToLeft = false, bottomToTop = false;
        
        //i and j are indicies representing row and column
        int i = 0, j = 0;

        //loop until out of bounds for matrix
        while(i >= top && i <= bottom && j >= left && j <= right){
            solution.push_back(matrix[i][j]); //directions will be dealth with in conditionals so always insert at beginning
    
            if(leftToRight){ //going from left to right
                if(j < right) //check if position is less than the right most position
                    ++j; //if it is increment it to go to next position
                else{ 
                    ++i; //otherwise we go down a row
                    ++top; //make the top bound smaller (top is now position + 1)
                    leftToRight = false; 
                    topToBottom = true; //next we will go top to bottom 
                }
            } 
            else if(topToBottom){ //going from top to bottom
                if(i < bottom)    //check if position is less than the bottom
                    ++i; //if it is then go down to next position
                else{
                    --j; //otherwise go left a position
                    --right; //make the right bounds smaller (right is now position - 1)
                    topToBottom = false;
                    rightToLeft = true; //next we will go right to left
                }
            }
            else if(rightToLeft){ //going from right to left
                if(j > left) //check if position is greater than the left most position
                    --j; //if it is then go left to next position
                else{
                    --i; //otherwise go up a position
                    --bottom; //make the bottom bound smaller (bottom is now position - 1)
                    rightToLeft = false;
                    bottomToTop = true; //next we will go bottom to top
                }
            }
            else if(bottomToTop){ //going from bottom to top
                if(i > top) //check if position is greater than top
                    --i; //if it is go up to next position
                else{
                    ++j; //otherwise go right a position
                    ++left; //make the left bounds smaller (left is now position + 1)
                    bottomToTop = false;
                    leftToRight = true; //next we will go left to right
                }
            }
        }
        return solution;
    }
};