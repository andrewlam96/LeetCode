//Solution 1: Using Set
//Time Complexity O(n) worst case O(log n) average because of each digit
//Space Complexity O(n) worst case O(log n) average because of each digit
class Solution {
    int getNumber(int& n){
        int total = 0;
        while(n > 0){
            int digit = n % 10; //get left most digit
            n /= 10; //make number smaller to access the rest of the number
            total += (digit * digit); //keep running total
        }
        return total;
    }
public:
    bool isHappy(int n) {
        set<int> visit;//container to hold visited numbers
        //keep looping until 1 or same number is reached
        while(n != 1 && (visit.find(n) == visit.end())){ 
            visit.insert(n);
            n = getNumber(n); //get next total
        }
        return n == 1; //see if final number is 1 or not
    }
};

//Solution 2: Using 2 Runners (Similar to 2 pointer idea)
//Time Complexity O(log n) reasons same as above
//Space Complexity O(1)
class Solution {
    //same as above except paramter is not a reference (since i call getNumber twice for fast)
    int getNumber(int n){
        int total = 0;
        while(n > 0){
            int digit = n % 10;
            n /= 10;
            total += (digit * digit);
        }
        return total;
    }
public:
    bool isHappy(int n) {
        //Make two runners
        int slow = n;
        int fast = getNumber(n);
        //Loop until fast reaches 1 or they reach same number
        while(fast != 1 && slow != fast){
            //update both
            slow = getNumber(slow);
            fast = getNumber(getNumber(fast));
        }
        return fast == 1;
    }
};