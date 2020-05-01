//Solution 1: Brute Force (Time Limit Exceeds)
//Time complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        //go through loop
        for(int i = 0; i < nums.size(); ++i){
            //set counters for zeros and ones
            int zero = 0, one = 0;
            //check each subarray
            for(int j = i; j < nums.size(); ++j){
                //increment counter for respective number
                if(nums[j] == 0) ++zero;
                else ++one;
                //if the number of zeros and ones are the same update max length
                if(zero == one) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

//Solution 2: Using a map
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> myMap;
        myMap[0] = -1; //put initial value in map first
        int maxLen = 0, count = 0;
        for(int i = 0; i < nums.size(); ++i){
            //if it is a 1 add to count otherwise subtract from count
            count += nums[i] == 1 ? 1 : -1;
            //if we find the corresponding value in map
            //we will update the length to either the maxlength or the index - (old index)
            if(myMap.find(count) != myMap.end())
                maxLen = max(maxLen, i - myMap[count]);
            else myMap[count] = i; //otherwise set key of count with value as index
        }
        return maxLen;
    }
};