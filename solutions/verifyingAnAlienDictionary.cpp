//Solution 1: Using a hashmap
//Time Complexity O(n)
//Space Complexity O(1) technically since we only use O(26) for the letters in the map
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() < 2) return true; //if nothing to compare to return true
        
        //wan to make our dictionary to use
        unordered_map<char, int> dict;
        int count = 0;
        //goes through every letter
        //since it is in order, I map the character to the value while incrementing it by 1
        for(auto &c : order) dict[c] = count++;
        
        //now we want to go through every word
        //can either start at index 0 and stop at size - 1 
        //or do what i did and start at index 1 and stop at size
        for(int i = 1; i < words.size(); ++i){
            //this "index" is used to keep track of the characters for the string
            int index = 0;
            
            //checks if the first letter of word1 is greater than first letter of word2 
            //if so, return false
            if(dict.find(words[i-1][index])->second > dict.find(words[i][index])->second) return false;

            //otherwise we check if the first letters are the same
            else if(dict.find(words[i-1][index])->second == dict.find(words[i][index])->second){
                ++index; //if they are we can move and check the next letters
                //we want to keep checking until 1 word reaches the end (index reaches the size)
                while(index < words[i-1].size() && index < words[i].size()){
                    //same logic as before check first letters of word1 vs word2
                    if(dict.find(words[i-1][index])->second > dict.find(words[i][index])->second) return false;
                    ++index; //increment to next letter 
                }
                //edge cases are if words are not same size and first word is longer than second word
                //i.e. apple vs app
                //at this point we got to app vs app so we then check size and if word1 size > word2 size return false 
                if(words[i-1].size() > words[i].size()) return false;
            }
            //if word1 < word2 for the first letter no need to worry (hence no case for it)
        }
        return true; //otherwise it must be true
    }
};

//Solution 2: Using Vector (same complexity as solution 1 but technically faster)
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() < 2) return true;
        
        //this is almost exactly the same as solution 1
        //use a vector instead
        vector<char> dict(26);
        int count = 0;
        //we want to set the values of the character 
        //use vector index to represent character i.e. a = 0 (hence we do - 'a')
        for(auto &c : order) dict[c - 'a'] = count++;
        
        //logic is exactly the same as solution 1
        //instead of checking the value of a map, we check the value of the index
        for(int i = 1; i < words.size(); ++i){
            int index = 0;
            if(dict[words[i-1][index] - 'a'] > dict[words[i][index] - 'a']) return false;
            else if(dict[words[i-1][index] - 'a'] == dict[words[i][index] - 'a']){
                ++index;
                while(index < words[i-1].size() && index < words[i].size()){
                    if(dict[words[i-1][index] - 'a'] > dict[words[i][index] - 'a']) return false;
                    ++index;
                }
                if(words[i-1].size() > words[i].size()) return false;
            }
        }
        return true;
    }
};