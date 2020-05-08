//Solution 1: using a map
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //use map to store number as key and count as value
        map<int, int> myMap;
        //go through the vector and add them to map and increase the count
        //we can also check if the majority element is there
        //if the value is greater than the size / 2 that is the element we want
        for(auto &i : nums){
            ++myMap[i];
            if(myMap[i] > nums.size() / 2) return i;
        }
        return 0;
    }
};

//Solution 2: sorting
//Time Complexity O(n log n)
//Space complexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //we can sort the vector
        //the middle index will be our solution
        //because it will have a total of n / 2 + 1 (at least)
        //by definition no matter where it's at, it has to pass through the middle point
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//Solution 3: Counting
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //idea is we check a number as our answer if the count is 0
        //we then add 1 if it is the same and subtract 1 if it is different
        //doing this, there will always be 1 element left since everything should cancel out
        //that element is our answer
        int count = 0, ans;
        
        for(auto &i : nums){
            if(count == 0) ans = i;
            
            if(i == ans) ++count;
            else --count;
        }
        
        return ans;
    }
};