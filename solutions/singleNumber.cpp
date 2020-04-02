//Solution 1: using map
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //use a map where key is integer and value is a bool (appears once or twice)
        map<int, bool> myMap;
        for(int i = 0; i < nums.size(); ++i){
            if(myMap.find(nums[i]) == myMap.end()){ //check if it is NOT in map
                myMap.insert(make_pair(nums[i], false)); //if it's not put it in map (bool can be either T of F) I chose false is once and true is twice
            }
            else{
                auto itr = myMap.find(nums[i]); //if it is in map, find it
                itr->second = true; //then change the bool to true
            }
        }
        for(auto m : myMap){ //go through map 
            if(m.second == false) //look for value that is false
                return m.first; //return that integer
        }
        return 0;
    }
};

//Solution 2: Bit manipulation
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int i : nums) {
            //use XOR: returns true if and only if one of the value is there otherwise it is false (0)
            //Idea is if every number is there twice, XOR would cancel them all out except for the single number
            //i.e. 1 3 2 3 1 
            // 1 ^ 3 ^ 2 ^ 3 ^ 1 == (1 ^ 1) ^ (2) ^ (3 ^ 3) == 0 ^ 2 ^ 0 == 2
            a ^= i;
        }
        return a;
    }
};