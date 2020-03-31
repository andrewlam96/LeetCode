//Solution 1: Comparing both vectors
//TIME LIMIT EXCEEDS SOLUTION
//Time Complexity O(n^2)
//Space Complexity O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> solution;
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                auto itr = find(solution.begin(), solution.end(), nums2[j]);
                if(nums1[i] == nums2[j] && itr == solution.end()){
                    solution.push_back(nums2[j]);
                }
            }
        }
        return solution;
    }
};

//Solution 2: using sets
//Time Complexity O(n + m)
//Space Complexity O(n + m)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mySet1;
        unordered_set<int> mySet2;
        vector<int> solution;

        //insert the vector elements into a set
        //by design, this will take care of duplicates
        for(auto &n : nums1) mySet1.insert(n);
        for(auto &n : nums2) mySet2.insert(n);
        
        //go through either set (it doesn't matter which one)
        for(auto &n : mySet1){
            //check if they are the same
            //if they are, push that value into the vector
            if(mySet2.find(n) != mySet2.end()) solution.push_back(n);
        }
        return solution;
    }
};