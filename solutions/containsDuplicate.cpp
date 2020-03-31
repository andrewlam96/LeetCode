//Time Complexity O(n)
//Space ComplexityO(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        
        for(int i = 0; i < nums.size(); ++i){
            auto itr = mySet.find(nums[i]); //make iterator to look at each value
            //if it is in the set return true 
            if(itr != mySet.end() && !mySet.empty()) return true; 
            mySet.insert(nums[i]); //insert value in set
        }
        return false; //return false if no duplicates
    }
};