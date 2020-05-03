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

//Time Complexity O(n log n)
//Space Complexity O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //sort vector so it is in order
        sort(nums.begin(), nums.end());

        //go from 1 to the end
        for(int i = 1; i < nums.size(); ++i){
            //if number before and current value is same return true
            if(nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};