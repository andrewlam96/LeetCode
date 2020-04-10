//Time compexity O(n^2 log n)
//Space Complexity O(n^2)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
        unordered_map<string, vector<string>> myMap; //map of the string and a vector
        for(int i = 0; i < strs.size(); ++i){
            string sortedWord = strs[i]; //make a copy of the string to sort
            sort(sortedWord.begin(), sortedWord.end()); //sort the string 
            //put string in map
            //since it is sorted, it sorted word will be the key and the pushed back value (actual word) will be in the vector
            myMap[sortedWord].push_back(strs[i]);
        }
        
        //Now the map will have the sorted word and a vector of all the words
        // we can go through the map and push each vector into the 2D vector for solution
        for(auto& m : myMap) solution.push_back(m.second);
        return solution;
    }
};