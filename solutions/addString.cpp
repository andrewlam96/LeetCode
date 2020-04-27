//Time Complexity O(max(m,n)) since it will go at most whatever is larger of num1 and num2
//Space Complexity O(n) since we need a new string and add to it
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, total = 0;
        string solution = "";
        //want to go until we get to the end of the two inputs and carry is 0
        while(num1.size() || num2.size() || carry){
            //the strings can be different sizes so we use if statements to check if they are > 0
            if(num1.size()){
                //we add to the total the last digit
                //and then we delete that from the string
                total += num1.back() - '0';
                num1.pop_back();
            }
            //do same thing from num1 to num2
            if(num2.size()){
                total += num2.back() - '0';
                num2.pop_back();
            }
            //we then add the carry to the total as well
            total += carry;

            //we then want to determine if there needs to be another carry
            //by dividing by 10, we will get 1 if it is 10+ or 0 if it is 9-
            carry = total / 10; 

            //we want to use modulo because the number could be >9 so we want last digit
            //additonally, if it is smaller it will just return the same thing
            total %= 10;
            solution += to_string(total); //change int to string and add it to string for solution
            total = 0; //reset total value
        }
        reverse(solution.begin(), solution.end()); //answer is in reverse order so we reverse the solution
        return solution;
    }
};