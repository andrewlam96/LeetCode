//Time Complexity O(n) or O(s1.size() + 26 * (s2.size() - s1.size()))
//Space Complexity O(n)
class Solution {
    bool matches(vector<int>& v1, vector<int>& v2){
        //goes through letters and checks if v1 equals v2
        for(int i = 0; i < 26; ++i){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        //if what we are checking for is bigger than it cannot be a permutation
        if (s1.size() > s2.size()) return false;
        
        //two containers to hold all lower case "letters" with value of 0
        //index is used as letter i.e. 0 = a, 1 = b, etc..
        vector<int> v1(26);
        vector<int> v2(26);
        
        //make all the letters in s1/v1 to 1
        //start input s2/v2 by having its first s1 size number of letters equal 1
        for(int i = 0; i < s1.size(); ++i){
            //-a means we are change the string/char to a number. I.e. ('a' becomes 0)
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        
        for(int i = 0; i < s2.size() - s1.size(); ++i){
            //check if they match
            if(matches(v1, v2)) return true;
            
            //if they don't add the next letter in s2 to equal 1 in v2
            //and get rid of the first letter from s2 (change it from 1 to 0 in vector)
            v2[s2[i + s1.size()] - 'a']++;
            v2[s2[i] - 'a']--;
        }
        return matches(v1, v2); 
    }
};