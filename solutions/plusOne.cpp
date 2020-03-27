//Time Complexity O(n) 
//Space Complexity O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //start at end of vector to go digit by digit
        for(int i = digits.size() - 1; i >= 0; --i){
            //if digit is 9 change it to 0
            if(digits[i] == 9){
                digits[i] = 0; 
            }
            else{ //by definition, the next iteration will either be a 9, the else statement, or out of loop
                ++digits[i]; //increment this digit by 1
                return digits; 
            }
        }
        //if it reaches here that means number is all 9s (i.e. 999)
        digits.push_back(0); //make space for one more digit
        digits[0] = 1; //change first digit to 1
        return digits;
    }
};