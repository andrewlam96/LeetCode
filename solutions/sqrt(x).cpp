//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int mySqrt(int x) {
        //since we're using ints, if it is less than 2 the square root will just be that number
        if(x < 2) return x; 
        
        //set up pivot, left, right
        //start at 2 since the square root cannot be less than that
        //similarly, the upperbound cannot be greater than number / 2 (x / 2)
        int pivot, left = 2, right = x / 2;
        
        while(left <= right){
            pivot = left + (right - left) / 2; // pivot = middle of left and right
            //we want to check if the pivot (root) number is the same as x
            //using long because max int * max int will not fit
            //to convert to long, one of the pivots has to be cast as a long as well
            long squared = (long)pivot * pivot; 
            if(squared == x) return pivot; //if they're the same return pivot
            else if(squared > x) right = pivot - 1; //otherwise if it is larger than we need a smaller number
            else left = pivot + 1; //other wise we need a larger number so make pivot one larger
        }
        return right; 
    }
};