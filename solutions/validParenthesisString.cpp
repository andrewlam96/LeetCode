//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool checkValidString(string s) {
        //idea is to check balance of parenthesis
        //so we count how many ( and !) we see
        int left = 0, notRight = 0;
        for(auto &c : s){
            //add 1 if we see ( otherwise we subtract 1
            left += c == '(' ? 1 : -1;
            //same idea where we add 1 if it is NOT ) otherwise we subtract 1 (it is ')')
            notRight += c != ')' ? 1 : -1;
            //if we have / start with ')' we return false
            if(notRight < 0) return false;
            //next we have to account for *
            //if there are too many, our left will be in the negatives so we get max of left or 0 for this case
            left = max(left, 0);
        }
        //then we return if left == 0 (if not then something unbalanced)
        return left == 0;
    }
};