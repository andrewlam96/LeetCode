//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int maximum = nums[0], prevMax = nums[0], prevMin = nums[0];
        int currMax, currMin;
        for(int i = 1; i < nums.size(); ++i){
            currMax = max(max(prevMax * nums[i], prevMin * nums[i]), nums[i]);
            currMin = min(min(prevMax * nums[i], prevMin * nums[i]), nums[i]);
            maximum = max(max(currMax, currMin), maximum);
            
            prevMax = currMax;
            prevMin = currMin;
        }
        return maximum;
    }
};