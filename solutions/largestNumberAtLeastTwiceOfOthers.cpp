//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        //use 2 maxes to keep track of largest 2 numbers and index of largest number
        int max = 0;
        int max2 = 0;
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            //first check if number is larger than largest number
            if(nums[i] > max){
                max2 = max; //if true make original max to second largest
                max = nums[i]; //save new max
                index = i; //save index of what new max is
            }
            //otherwise check if it is second largest number
            else if(nums[i] > max2){
                max2 = nums[i];
            }
        }
        //check if largest number is at least twice as large as the second largest number and return index
        if(max >= 2 * max2)
            return index;
        else
            return -1;
    }
};