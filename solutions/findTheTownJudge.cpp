//Solution 1: using 2 maps
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //if there is only 1 person it has to be true
        if(N == 1) return N;

        //using one map to store the pairs
        //use another to store the count of the second index
        map<int, int> myMap;
        map<int, int> count;

        //go througb vector of vector 
        //and put in pairs in one map and count for another
        for(auto &v: trust){
            myMap[v[0]] = v[1];
            count[v[1]]++;
        }
        
        //go through count map
        //if the count is N - 1 (means everybody but judge trusts him)
        //then check if "the supposed judge" trusts anyone that trusts him
        //basically check is the first of count is the same as any key in the paired map
        //if it doesn't then it exists and is true otherwise we return -1
        for(auto &m : count){
            if(m.second == N - 1 && myMap.find(m.first) == myMap.end()) return m.first;
        }
        return -1;
    }
};

//Solution 2: using 1 arrays
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //if the size is less than n - 1 there can't be a judge
        if(trust.size() < N - 1) return -1;
        
        //we want a vector from 1 to N so (use N+1)
        vector<int> trustScores(N+1,0);
        
        //doesn't matter which way we do it
        //but we want to increment and decrement from the towns people and judge
        for(auto &v : trust){
            trustScores[v[0]]--;
            trustScores[v[1]]++;
        }
        
        //we then go back through vector and if that index equals N - 1 wq have our judge
        for(int i = 1; i <= N; ++i){
            if(trustScores[i] == N - 1) return i;
        }
        
        return -1;
    }
};