//Time Complexity O(2^n)
//Space Complexity O(2^(n-1))
class Solution {
public:
    string countAndSay(int n) {
        //base cases
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        //initial case
        string prev = "11";
        
        //start at 3 (since 1 and 2 are already base cases)
        for(int i = 3; i <= n; ++i){
            prev += '/'; //need a dummy character so loop can run 1 extra time
            
            int count = 1; //counter for repeated numbers
            string temp = ""; //temp string to hold new number
            
            //start at 1 and go until you reach all the numbers in previous string
            for(int j = 1; j < prev.size(); ++j){ 
                if(prev[j] != prev[j-1]){ //check the current number with the number before
                    temp += count + '0'; //if they're not the same add the count of first number to temp
                    temp += prev[j-1]; //then add the first number to temp after the count
                    count = 1; //change the counter back to 1
                }
                else ++count; //if they are same increase counter
            }
            prev = temp; //update the number to be used again
        }
        return prev;
    }
};