//Time Complexity O(n)
//Space Complexity O(1)
//For this problem, we want to find the total max profit and we can make multiple sells and buys
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int maxProfit = 0;
        //can start from 1 instead of 0 since we want to compare to previous number as well
        for(int i = 1; i < prices.size(); ++i)
            //idea is that we can just add up every increment from a lower price to a higher price and that will give us the max profit
            if(prices[i] > prices[i - 1]) maxProfit += (prices[i] - prices[i - 1]); 
        return maxProfit;
    }
};