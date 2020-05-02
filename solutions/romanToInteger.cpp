//Time Complexity O(n)
//Space Complexity O(1) sine we use map for 7 roman charactes
class Solution {
public:
    int romanToInt(string s) {
        //map our roman character to their respective number
        unordered_map<char,int> num = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        //our solution
        int dec = 0;

        //our previous if we have to do subtraction
        //i.e. IV = 4 s we need to know I
        int prev = num[s[0]];

        //go through string
        for(int i = 0; i < s.length(); ++i){
            //this means the current number is larger than the previous number so we need to subtract
            //since we have already added the previous number, we have to subtract it twice
            //so we add the current number and subtract 2*prev
            if(num[s[i]] > prev){
                dec += num[s[i]] - 2 * prev;
            }
            //this means it is larger so we can just add it
            else{
                dec += num[s[i]];
            }
            //update previous number
            prev = num[s[i]];
        }
        return dec;
    }
    
};