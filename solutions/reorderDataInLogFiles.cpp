//Time Complexity O(n log n) Had to sort data
//Space Complexity O(n) or O(1)

//wrote own sort function to sort the different data
//Keep in mind that true means s1 < s2
//false means nothing happens
//for this we want lexicographical order for letter types and input order for digit types
bool logSort(const string& s1, const string& s2){
    //first, we want to find the first space since the data type afterwards tells us what log type it is
    //if it is a a digit, it is a digit type otherwise its a letter type
    int s1Index = s1.find(' '), s2Index = s2.find(' ');

    //edge case is if the substring from after the space to the end is the same for both
    //then we want to return what is smaller from beginning up until before the space (technically we could go until the space but for logical purposes I chose before)
    if(s1.substr(s1Index + 1) == s2.substr(s2Index + 1))
        return s1.substr(0, s1Index - 1) < s2.substr(0, s2Index - 1);
    
    //next we want to check if both are NOT digits (letter logs)
    //this means we want lexigraphical order
    //we just compare the substrings after the first space 
    else if(!isdigit(s1[s1Index+1]) && !isdigit(s2[s2Index+1]))
        return (s1.substr(s1Index + 1) < s2.substr(s2Index + 1));
    
    //finally we now have either 1 letter and 1 digit log or 2 digit logs
    //if the first one is NOT a digit we want to return true since it has to go before a digit log
    //otherwise we want to keep the order it came in (return false)
    else{
        if(!isdigit(s1[s1Index+1])) return true;
        return false;
    }
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //NOTE that an extra vector is not needed
        //but for some reason it gives a faster runtime on leetcode
        vector<string> solution;
        //go through the vector of strings
        //and push all the data 
        for(auto &s : logs)
            solution.push_back(s);

        //use stable sort so that ties can be handled 
        stable_sort(solution.begin(), solution.end(), logSort);
        return solution;
    }
};