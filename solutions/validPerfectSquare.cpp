//Solution 1: Newton's Method
//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        //1 is a perfect square
        if(num < 2) return true;
        
        //we want the root of x^2 - num = 0

        //first we need a starting position
        //we start at num / 2 since that's the smallest it can be
        long x = num / 2;

        //we want x^2 to be num so if it is larger
        //we divide num by x then add x to it. then divide by 2
        while(x * x > num){
            x = (x + num / x) / 2;
        }

        //once it is not x^2 is not larger than num
        //we return whether x^2 is equal to num or not
        return(x * x == num);
    }
};