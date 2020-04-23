//Time Complexity O(n * sqrt(n))
//Space Complexity O(n)
class Solution {
public:
    int numSquares(int n) {
        if(n <= 3) return n; //if n <= 3 then just return it (no need to go further) 
        
        //want to store all solutions somewhere and set them up with initial values of max
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0; //base case
        
        //want to go through all numbers
        for(int i = 1; i <= n; ++i){
            //from there, on each number go until you reach at most the square of that number
            for(int j = 1; j * j <= i; ++j){ 
                //to find the result, you want to compare the number to the minimum square values it takes
                //since each index is max int at first, we will get min of that compared to number - squares
                //i.e. 3 will check 3-1(square) this will get us index of 2 (which is 2) + 1 
                //so solution is 3 since which is correct 1^2 (three times)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};