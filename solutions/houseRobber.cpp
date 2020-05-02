//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int prevMax = 0, currMax = 0;
        //go through all numbers in vector
        for(auto &i : nums){
            //idea is we want to keep track of 2 maxes (not necessarily alternating though)
            //we know we can add to the previous max so we set max to be either the previous max + current or the current max
            int temp = currMax; //so we don't lose current max
            currMax = max(prevMax + i, currMax); //want max as either prevmax + curr or currMax
            prevMax = temp; //update the previous max
        }
        
        return currMax;
    }
};