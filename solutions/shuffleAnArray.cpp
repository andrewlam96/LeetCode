class Solution {
    //make two vectors one we don't change and another we can modify
    vector<int> original;
    vector<int> vecCopy;
public:
    Solution(vector<int>& nums) {
        //when we use the constructor, we set both vectors to the input vector
        original = nums;
        vecCopy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        //after the reset, we set the copy back to the original and return one of them (since they are the same it doesn't matter which one)
        vecCopy = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //we want to randomly shuffle the numbers so
        //first we go through all the values
        for(int i = 0; i < vecCopy.size(); ++i){
            //then we swap that value with a random indexed value
            swap(vecCopy[i], vecCopy[rand() % vecCopy.size()]);
        }
        return vecCopy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */