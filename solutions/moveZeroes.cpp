//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int toSwap = 0;
        for(int i = 0; i < nums.size(); ++i){
            //if a number is not equal to zero set it to the front
            //the index then move to the next one so the numbers will stay in order
            if(nums[i] != 0) nums[toSwap++] = nums[i];
        }
        //at this point all numbers NOT zero will be in order
        //we just have to set all numbers at end to zero
        for(int i = toSwap; i < nums.size(); ++i){
            nums[i] = 0;
        }
    }
};