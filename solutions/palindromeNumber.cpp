//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; //if negative it is false (- sign)
        
        long rev = 0; //could potentially get larger than int so use a long
        int xCopy = x; //make a copy of original so we can use orignal later to compare

        //want to keep looping until we get every digit
        while(xCopy){
            //we want to multiply answer by 10 then add the new digit
            //i.e. 123 -> 0 + 3 -> 3*10 + 2 = 32 -> 32 * 10 + 1 = 321 so false
            rev = (rev * 10) + (xCopy % 10);
            xCopy /= 10; //make number smaller
        }
        //check if the reverse is the same as original
        return rev == x;
    }
};