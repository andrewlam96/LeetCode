//Time Complexity O(n^2)
//Space Complexity O(n^2)
class Solution {
    //helper function based on twoSUMII 
    void twoSumII(vector<int> &v, int i, vector<vector<int>> &solution){
        //Idea is we will have a starting point at index i
        //then the other two indices are the one right after it and at the end (since it is ordered this works)
        //then we will move lo up and hi down until they meet

        //set lo as point after index i
        //set hi has ending index
        int lo = i + 1, hi = v.size() - 1;
        //want to loop until they meet
        while(lo < hi){
            //sum is the sum of the three points
            int sum = v[i] + v[lo] + v[hi];

            //again, we want to avoid duplicates so if we get duplicate number we skip it
            if(sum < 0 || (lo > i + 1 && v[lo - 1]  == v[lo])) ++lo;
            else if(sum > 0 || (hi < v.size() - 1 && v[hi] == v[hi + 1])) --hi;
            //at this point it means sum is 0 so we push back the 3 numbers
            else solution.push_back({v[i], v[lo++], v[hi--]});
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the vector to work with numbers easier
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        //go through the loop and stop at end or when index is greater than 0
        //NOTE that we technically don't need to check the index but it makes runtime faster 
        //because we don't have to do extra computes since it cannot be 0 if it is ordered
        for(int i = 0; i < nums.size() && nums[i] <= 0; ++i){
            //we want to skip same numbers since we will get diplicates
            //do only run helper function if it's first or not a duplicate
            if(i == 0 || nums[i - 1] != nums[i])
                twoSumII(nums, i, solution);
        }
        return solution;
    }
};