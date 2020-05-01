//Time Complexity O(n) i think for stringstream copying string
//Space Complexity O(n) since we copy the string
class Solution {
public:
    int myAtoi(string str) {
        //if size is 0 return 0
        if(str.size() == 0) return 0;
        
        //use stringstream to parse string
        stringstream ss(str);

        //mt temp variables
        string s;
        long long i;

        //first i want to get it as a string to see if there is any leading character
        //NOTE trailing characters that are not numbers do not matter
        ss >> s;

        //we also don't care if it is a space so we can use function find...of to skip spaces and get index of next char
        int notWhite = s.find_first_not_of(' ');

        //important if the input is only spaces we need to check for that 
        //so we compare and if index leads to the size then we return 0
        if(notWhite >= s.size()) return 0;
        
        //no we check if it is a number first or not 
        //so we check if it is either a digit or a '-' or a '+'
        if(isdigit(s[notWhite]) || s[notWhite] == '-' || s[notWhite] == '+'){
            //there can be characters after the numbers so we want to use stringstream again
            //we have to use another object since we cannot copy string without constructor
            stringstream iss(s); 
            iss >> i; //only want "long" (number) portion of string
        }

        //other wise it means it has leading words so return 0
        else return 0;

        //cases if number is larger than int max and min
        if(i <= INT_MIN) return INT_MIN;
        if(i >= INT_MAX) return INT_MAX;

        //otherwise return the number
        return i;
    }
};