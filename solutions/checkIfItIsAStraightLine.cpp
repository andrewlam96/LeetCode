//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //we want variables for slope and in slope before(prev)
        double slope = 0, prev;

        //since we are comparing the two vectors next to each other
        //we will start at 1 and go to end
        for(int i = 1; i < coordinates.size(); ++i){
            //formula for slope is (y2 - y1) / (x2 - x1)
            //so we want variables for them
            //x1 and y1 are the first number from index and x2 and y2 are second number from index
            int x1 = coordinates[i][0];
            int x2 = coordinates[i - 1][0];
            int y1 = coordinates[i][1];
            int y2 = coordinates[i - 1][1];

            //cannot divide by zero so we check if the denominator is 0
            if(x2 - x1 == 0) return false;

            //calculate slope
            slope = (double)(y2 - y1) / (double)(x2 - x1);

            //if they are not the same and it is not the first iteration then it is false
            if(slope != prev && i != 1) return false;

            //set prev as the slope to be compared to in next iteration
            prev = slope;
        }
        //otherwise it is a straight line
        return true;
    }
};