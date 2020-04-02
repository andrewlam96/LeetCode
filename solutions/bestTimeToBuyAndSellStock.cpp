//Solution 1: Brute Force TIME LIMIT EXCEEDS
//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; //max profit starts at 0
        for(int i = 0; i < prices.size(); ++i){ 
            for(int j = i + 1; j < prices.size(); ++j){ //gets element immediately after first
                int profit = prices[j] - prices[i]; //find difference between second day and first
                if(profit > maxProfit) maxProfit = profit; //if profit is larger it is now new max profit
            }
        }
        return maxProfit;
    }
};

//Solution 2: One Pass
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = numeric_limits<int>::max(); //set minimum (use max int so all numbers after it will be samller)
        int maxProfit = 0; //max profit starts at 0-
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < minPrice) minPrice = prices[i]; //if number is smaller than minimum make it the min
            //if the difference between trhe current price and min is larger than max profit
            //make that the new max profit
            else if(prices[i] - minPrice > maxProfit) maxProfit = prices[i] - minPrice;  
        }
        return maxProfit;
    }
};