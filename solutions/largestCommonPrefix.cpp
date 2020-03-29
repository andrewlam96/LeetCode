//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        //sort vector first so the smallest word can be used for comparisons
        sort(strs.begin(), strs.end()); 
        
        string firstWord = strs[0]; //first word in vector
        string solution = ""; 
        //only have to check, at max, the size of first word characters
        for(int i = 0; i < firstWord.size(); ++i){ 
            for(int j = 0; j < strs.size(); ++j){ //loop through vector
                if(firstWord[i] != strs[j][i]){ //checking the letters from word 1 to other words at index [i]
                    return solution; //if not the same for every word return the current solution (String we have made)
                }
            }
            solution += firstWord[i]; //update solution
        }
        return solution;
    }
};