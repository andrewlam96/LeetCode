//Solution 1: Brute Force
//Time Complexity O(n^2)
//Space Complexity O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){ //loop from beginning to end
            for(int j = i + 1; j < nums.size(); ++j){ //start from second index and loop to end
                //if the nums add up to target put the INDICIES into vector
                //instead of using push back i can create vector directly and return it
                //Note that there is no name for this vector as i am just returning the object I am creating
                if(nums[i] + nums[j] == target) return vector<int> {i, j};  
            }
        }
        return vector<int>(); //returning empty vector
    }
};

//Solution 2: Hash Map
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap; //map where key is the number and value is the index
        for(int i = 0; i < nums.size(); ++i){
            int diff = target - nums[i]; //find the difference between the target and current number
            auto itr = myMap.find(diff); //search to see if the difference of those numbers is in map already
            //if it is in map already return vector with the two values
            //NOTE that the order does matter so the mapped value goes first and then the current value
            //mapped value by definition of being inserted already must have a smaller index
            if(itr != myMap.end()) return vector<int> {itr->second, i};
            else myMap.insert({nums[i], i}); //otherwise insert the value and index into map
        }
        return vector<int>();//return an empty vector if not found
    }
};