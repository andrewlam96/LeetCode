//Time Complexity O(log n) since there will be approximately log10(n) digits
//Space Complexity O(1)
class Solution {
public:
    int reverse(int x) {
        //use a long because answer could potentially be larger than an int (which we will return 0)
        long reverse = 0;
        //want to go through every digit
        //so we so until the initial digit becomes 0
        while(x != 0){
            //formula is to multiply answer by 10 then all the rightmost digit from original number
            //i.e. -123 (will use [] to indicate x % 10 number)
            //[-3] -3 
            //[-2] -3 * 10 + (-2) = -32
            //[-1] -32 * 10 + (-1) = -321 
            reverse = reverse * 10 + x % 10;
            x /= 10; //make number smaller
        }
        //if number is not an int return 0 otherwise return the reverse 
        return (reverse < INT_MIN || reverse > INT_MAX) ? 0 : reverse;
    }
};