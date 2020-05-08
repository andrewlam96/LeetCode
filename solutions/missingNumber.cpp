//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Idea is to use Gauss' formula
        //so total = n(n+1)/2
        //we know there is one number missing so we just get total and subtract every number
        //the number missing is what total will end up being
        
        int n = nums.size();
        int total = n * (n + 1) / 2;
        for(auto &i : nums){
            total -= i;
        }
        return total;
    }
};