//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //add up all numbers within vector (can also do this with a loop)
        auto total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            //check if sum is equal to the total - sum - current number
            //in this case, sum represents the numbers up until an index 
            //and the equation represents the other side of that index
            if(sum == (total - sum - nums[i])){
                return i;
            }
            else{
                sum += nums[i];
            }
        }
        return -1;
    }
};