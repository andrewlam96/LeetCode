//Time Complexity O(n^2)
//Space Complexity O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> solution(numRows);
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j < i+1; ++j){ //terminating condition only needs to go up to what i + 1 is since each column increases by 1
                if(j == 0 || j == i) solution[i].push_back(1); //if it's the beginning or end, number will be 1
                //otherwise look up 1 row (i-1) and at the index before and same index (j-1 and j) to get sum
                else
                    solution[i].push_back(solution[i-1][j-1] + solution[i-1][j]);
            }
        }
        return solution;
    }
};