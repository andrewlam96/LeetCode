//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        //counter to find index
        int count = 0;
        //want map for the character and amount of times it appears
        unordered_map<char, int> myMap;

        //go through string and add 1 every time we see that character
        for(auto &c : s){
            myMap[c]++;
        }

        //again go through string again and check (starting from beginning) if that mapped character has value of 1
        for(auto &c : s){
            if(myMap[c] == 1) return count;
            ++count; //increment counter
        }
        //otherwise return -1
        return -1;
    }
};