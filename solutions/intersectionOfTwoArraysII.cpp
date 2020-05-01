//Time Complexity O(m + n)
//Space Complexity O(min(n,m))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //use map to store count of values
        //vector for solution
        unordered_map<int, int> myMap;
        vector<int> solution;

        //go through first vector and add to map
        for(auto &i : nums1){
            myMap[i]++;
        }

        //go through second vector
        for(auto &i : nums2){
            //search if the key exist in map and if the val is > 0 
            if(myMap.find(i) != myMap.end() && myMap[i] > 0){
                myMap[i]--; //if true we want to make the count smaller
                solution.push_back(i); //and put it in vector 
            }
        }
        return solution;
    }
};