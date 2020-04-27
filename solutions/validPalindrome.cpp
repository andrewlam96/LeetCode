//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        //if the size is less than 2 then by definition it is true
        if(s.size() < 2) return true;

        //make two indices for the beginning and end to compare
        int leftIndex = 0;
        int rightIndex = s.size() - 1;

        //want to keep comparing until left index becomes the same or greater than right index
        while(leftIndex < rightIndex){
            //check if both characters are alphanumeric (letter or number)
            if(isalnum(s[leftIndex]) && isalnum(s[rightIndex])){
                //if their lowercase version is not the same then it cannot be a palindrome
                if(tolower(s[leftIndex]) != tolower(s[rightIndex])) return false;
                //otherwise it means they are the same so move the indices (left goes up right down back)
                ++leftIndex;
                --rightIndex;
            }
            //could have used !isalnum but i chose to use isalnum 
            //so that means if it is alphanumeric the opposite isn't so move that index
            else if(isalnum(s[leftIndex])) --rightIndex;
            else if(isalnum(s[rightIndex])) ++leftIndex;
            //other wise both are not alphanumeric
            //so move both indices
            else{
                ++leftIndex;
                --rightIndex;
            }
        }
        return true;
    }
};