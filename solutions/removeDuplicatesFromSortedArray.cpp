//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;
        for(int i = 1; i < nums.size(); ++i){ //start at 1 so we can access previous number as well
            if(nums[i] == nums[i - 1]) ++counter; //if they are the same add too counter
            else nums[i - counter] = nums[i]; //otherwise we will replace the next index with the next number
        }
        return nums.size() - counter; //return the size - cnt 
    }
};
