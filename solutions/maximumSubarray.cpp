//Solution 1: Divide and Conquer
//Time Complexity O(n log n)
//Space Complexity O(log n)
//NEED TO REVIEW THIS QUESTION AND RECOMMENT ON SOLUTION
class Solution {
    int crossSum(vector<int>& nums, int left, int right, int p){
        if(left == right)  return nums[left];
        
        int leftSubSum = numeric_limits<int>::min();
        int currSum = 0;
        for(int i = p; i > left - 1; --i){
            currSum += nums[i];
            leftSubSum = max(leftSubSum, currSum);
        }
        
        int rightSubSum = numeric_limits<int>::min();
        currSum = 0;
        for(int i = p + 1; i < right + 1; ++i){
            currSum += nums[i];
            rightSubSum = max(rightSubSum, currSum);
        }
        
        return leftSubSum + rightSubSum;
    }
    
    int helper(vector<int>& nums, int left, int right){
        if(left == right) return nums[left];
        
        int p = (left + right) / 2; 
        int leftSum = helper(nums, left, p);
        int rightSum = helper(nums, p + 1, right);
        int cross = crossSum(nums, left, right, p);
        
        return max(max(leftSum, rightSum), cross);
    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

//Solution 2: Greedy
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums.front();
        
        //set max and current total to the first element
        int maximum = nums[0], current = nums[0];
        
        //start from second element and go to end
        for(int i = 1; i < nums.size(); ++i){
            //set current to whatever is larger: the current total + current index, or the current index val
            current = max(nums[i], current + nums[i]);
            //set the max to the max of either: the current max 
            maximum = max(maximum, current);
        }
        return maximum;
    }
};