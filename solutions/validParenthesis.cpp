//Time complexity is O(n)
//Space complexity is O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack; //use stack to store character because we want to check them in LIFO order
        char temp;
        for(auto& c : s){
            //3 conditions made based on assumption problem only uses '(', '{', '[', ')', '}', ']'
            if(c == ')' && !myStack.empty()){ //check for ending conditions and if stack is empty (edge cases)
                temp = myStack.top();
                if(temp == '(')
                    myStack.pop();
                else
                    return false;
            }
            else if(c == '}' && !myStack.empty()){
                temp = myStack.top();
                if(temp == '{')
                    myStack.pop();
                else
                    return false;
            }
            else if(c == ']' && !myStack.empty()){
                temp = myStack.top();
                if(temp == '[')
                    myStack.pop();
                else
                    return false;
            }
            else{
                myStack.push(c); //insert if it is not an ending 
            }
        }
        return myStack.empty(); //if stack is empty it is true else it is false
    }
};