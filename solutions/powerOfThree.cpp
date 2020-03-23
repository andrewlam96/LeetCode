//Solution 1: Loop
//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 1) //only want to check if number is greater than 0
        {
            if(n % 3 != 0) //if it isn't divisible by 3 it cannot be a power
                return false;
            n /= 3; //make number smaller until it becomes 1
        }
        return n == 1; //if it is 1 than it returns true else false
    }
};

//Solution 2: Math
//Time Complexity: Depnds on what fmod() time complexity is
//Space Complexity O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        //formula is if (base10) log(n) / log(3) is an integer than it is a power of 3 
        //fmod checks if logn / log3 mod 1 equals 0
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};