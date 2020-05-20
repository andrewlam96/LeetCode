//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int singleElement = 0; //make sure to set this to 0
        for(auto &i : nums){
            //we want to XOR each element
            //if there is a pair, it will return 0
            //otherwise it will be whatever it XORS
            singleElement ^= i;
        }
        return singleElement;
    }
};