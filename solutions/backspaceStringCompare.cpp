//Time Complexity O(m + n)
//Space Compexity O(m + n)
class Solution {
    //make a function to return the modified string for each case
    string modifyString(string &s){
        string myString = "";
        //use a stack so we can pop the last character if we see '#'
        stack<char> myStack;
        //go through string
        for(auto& c : s){
            //if it is not # push element into stack
            if(c != '#') myStack.push(c);
            //otherwise we have to check if it is not empty and pop 
            //reason to check instead of else if for cases like a##c we cannot pop twice
            else if(!myStack.empty()) myStack.pop();
        }
        
        //go through stack and put characters into string
        //it will be backwards but it shouldn't matter because if they are the same their reverse is the same as well
        while(!myStack.empty()){
            myString += myStack.top(); //get the first (top) element and add that character to the string
            myStack.pop(); //delete that character from the stack
        }
        return myString;
    }
public:
    bool backspaceCompare(string S, string T) {
        string newS = "", newT = "";
        //call the helper function
        newS = modifyString(S);
        newT = modifyString(T);
        
        //if they are the same then return true other wise return false
        if(newS == newT) return true;
        return false;
    }
};
