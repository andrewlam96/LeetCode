//Solution 1: using sort
//Time Complexity: O(n log n)
//Space Complexity O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        //if they are not the same size they cannot be anagrams
        if(s.size() != t.size()) return false;
        //sort the two strings so they are in alphabetical order
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; //compare and return the result
    }
};

//Solution 2: hash table
//Time Complexity: O(n)
//Space Complexity: O(1) technically because we use finite amount of space for letters (26)
class Solution {
public:
    bool isAnagram(string s, string t) {
        //if they are not the same size they cannot be anagrams
        if(s.size() != t.size()) return false;
        vector<int> letters(26); //vector to store the letters
        //add 1 to the letter index of each letter in string s
        for(int i = 0; i < s.size(); ++i){
            letters[s[i] - 'a']++;
        }
        //subtract 1 from letter index of each letter in string t (order doesn't matter can add/sub in either order)
        for(int i = 0; i < t.size(); ++i){
            letters[t[i] - 'a']--;
            //check if the letter is less than 0 
            //if it is less than 0 then it does not match with string s so they're not anagrams
            if(letters[t[i] - 'a'] < 0) return false; 
        }
        return true;
    }
};