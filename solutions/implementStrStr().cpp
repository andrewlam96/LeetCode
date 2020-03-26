//Time Complexity O(n) from find 
//Space Complexity O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0; //if empty return 0

        int found = haystack.find(needle);
        //compare to string::npos (checks if there is no position for the string)
        //if not true then it must be 
        if(found != string::npos) return found;
        else return -1; //not found return -1
    }
};