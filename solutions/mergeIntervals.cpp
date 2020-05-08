//Time Complexity O(n log n)
//Space Complexity O(1) since we don't need to copy anything

//we want to write our own sort function
//we want the interval to be sorted by beginning number
bool sortedInterval(const vector<int> &v1, const vector<int> &v2){
        return v1[0] < v2[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //if it is empty return nothing
        if(intervals.empty()) return {};
        //to sort, we use sort with begin to end and also make sure to call our user defined sort function as 3rd parameter
        sort(intervals.begin(), intervals.end(), sortedInterval);
        
        //2D vector to store answer
        vector<vector<int>> solution;
        //make sure to put first vector into solution
        solution.push_back(intervals[0]);

        //want to go through all vector of vectors
        for(auto& v : intervals){
            //NOTE make sure to use a reference since we will be changing the value
            //we want the last vector since it should have the last number in 2nd index
            vector<int> &lastInterval = solution.back();

            //we then compare the first number of current index to last numbe rof last index
            //if first index of current is the same or less than the 2nd index of last
            //we can merge them (want max of the 2nd indices)
            if(v[0] <= lastInterval[1]) lastInterval[1] = max(v[1], lastInterval[1]);

            //otherwise the interval do not overlap so add the vector to solution
            else solution.push_back(v);
        }
        return solution;
    }
};