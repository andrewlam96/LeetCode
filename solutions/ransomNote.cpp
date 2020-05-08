//Time Complexity O(n + m)
//Space Complexity O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //use vector where index is "letter" (0 = a) and value is count
        vector<int> letters(26);

        //go through magazine and increase the count for each letter in there
        for(auto &c : magazine){
            ++letters[c - 'a'];
        }
        
        //go through ransom note
        for(auto &c : ransomNote){
            //decrease the counter for letter found
            --letters[c - 'a'];

            //if the count is less than 0 then return false
            if(letters[c - 'a'] < 0) return false;
        }
        return true;
    }
};