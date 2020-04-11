//Time Complexity O(1)
//Space Complexity O(n)
class MinStack {
    //use two stacks
    //one for normal operations and another to return the min
    stack<int> minStack;
    stack<int> myStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        //always want to push the first value
        //that will be our "min"
        if(minStack.empty()) minStack.push(x);

        //if we find a value less than that, we will push it to the min stack 
        else if(x <= minStack.top()) minStack.push(x);
        
        myStack.push(x); //always push to normnal stack
    }
    
    void pop() {
        //if the value we're removing is the same value as the one in the min stack remove that too
        if(minStack.top() == myStack.top()){
            minStack.pop();
        }
        myStack.pop(); //always remove the top value from the normal stack
    }
    
    int top() {
        return myStack.top(); //return our normal stack top value
    }
    
    int getMin() {
        return minStack.top(); //top value from min stack should be the min
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */