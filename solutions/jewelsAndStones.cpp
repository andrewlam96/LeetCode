//Time Complexity O(J + S) or O(n + m)
//Space Complexity O(J) or O(n)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        //since each character is unique we can use set instead of a map
        unordered_set<char> letters;

        //put all letters in jewel in set
        for(auto &c : J){
            letters.insert(c);
        }
        
        int counter = 0;

        //go through stones
        for(auto &c: S){
            //if jewel is in stone
            //increment counter
            if(letters.find(c) != letters.end()){
                ++counter;
            }
        }
        return counter;
    }
};