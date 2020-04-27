//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> words;
        //want to add anything not a letter (i chose '.') to the the end of the string
        //because it could end with a letter and code would then not work
        paragraph += "."; 
        string word = ""; //our temp word 
        //go through the string
        for(int i = 0; i < paragraph.size(); ++i){
            //if the character is a letter add it to the word (as a lowercase letter)
            if(isalpha(paragraph[i])) word += tolower(paragraph[i]);
            //otherwise it means its not a letter
            //so we want to first add the word before we have reached the letter
            //the else if statement also helps with situations of multiple non letters (...)
            //it will skip them since the word size will be 0
            else if(word.size()){
                words[word]++; //we want to insert word or and add 1 to the value
                word.clear(); //make sure to reset the size to 0 after putting word in map
            }
        }
        
        //at this point the map should be filled with every word
        //we will traverse through the banned list (vector)
        //and set the values of banned words to 0
        for(auto &s: banned){
            if(words.find(s) != words.end()) words[s] = 0;
        }
        
        //the we want the word with the highest value
        //by definiton there will only be 1 that is larger than the rest
        int max = 0;
        string solution;
        //go through the words in map
        //and check if they are greater than max
        //if it is, set the value to max and solution to the key (word)
        for(auto &w: words){
            if(w.second > max){
                max = w.second;
                solution = w.first; 
            }
        }
        return solution;
    }
};