//Solution 1: Dynamic Programming
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int climbStairs(int n) {
        //if 1 or 2 return that number
        if(n <= 2) return n;
        
        //vector to store all solutions
        vector<int> dp(n+1);
        //base cases
        dp[1] = 1;
        dp[2] = 2;

        //go from 3 to n
        for(int i = 3; i <= n; ++i){
            //value for index is the previous 2 added together
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        //return index at n
        return dp[n];
    }
};

//Solution 2: Fibonacci 
//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int climbStairs(int n) {
        //use fibonacci formula which is: 
        //Phi^n - phi^n / sqrt(5) where Phi = 1 + sqrt(5) and phi is 1 - sqrt(5)
        //NOTE we used n + 1 in code because it is 0 indexed so we have to add 1 to start from 1
        //ALSO don't forget to initially use doubles since the number is going to be a decimal before all calculations are done
        double sqrt5=sqrt(5);
        double fib = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return fib / sqrt5;
    }
};
