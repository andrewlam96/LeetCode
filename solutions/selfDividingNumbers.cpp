//Time Complexity O(n * log(right))  
//Space Complexity O(n^2)
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> solution;
        
        //loop through the indicies asked for
        for(int i = left; i <= right; ++i){
            int copyIndex = i; //make a copy of i so it can be moodified
            bool pass = true; //keep track if number % digit = 0
            while(copyIndex > 0){ //loop to check all digits in number
                int digit = copyIndex % 10; //get rightmost digit
                if(digit == 0 || i % digit != 0) { //cannot % by 0 also want it to have 0 remainder
                    pass = false;
                    break;
                }
                copyIndex /= 10; //make number smaller 
            }
            if(pass) solution.push_back(i);
        }
        return solution;
    }
};