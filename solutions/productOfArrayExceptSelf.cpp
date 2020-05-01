//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //idea is that you want to multiply everything before/after an index
        //you can get the after by going from 0 -> size and multiplying product
        //you can get the before by going from size - 1 -> 0 and multiplying product
        //then solution is multiple the opposite i.e. 123 -> 112 (before) -> (631) (after (dont forget it's in reverse order))
        //then solution is product of indices (112) * (631) = (6 3 2) 
        vector<int> solution(nums.size());
        int product = 1;
        for(int i = 0; i < nums.size(); ++i){
            //set index as product
            solution[i] = product;
            //update product by multiplying values of current index
            product *= nums[i];
        }
        
        product = 1;
        //start from size - 1 and go to beginning
        for(int i = nums.size() - 1; i >= 0; --i){
            //can do 2 steps in one. Get product and instead of setting, you can multiply it with current index
            solution[i] *= product; 
            //again, update product
            product *= nums[i];
        }
        return solution;
    }
};