//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> solution;

        //go through numbers from 1 to n
        for(int i = 1; i <= n; ++i){

            //if it is divisible by 15 put FizzBuzz
            if(i % 3 == 0 && i % 5 == 0) solution.push_back("FizzBuzz");

            //divisible by 3 put Fizz
            else if(i % 3 == 0) solution.push_back("Fizz");

            //divisible by 5 put Buzz
            else if(i % 5 == 0) solution.push_back("Buzz");

            //otherwise just put the number
            else solution.push_back(to_string(i));
        }
        return solution;
    }
};