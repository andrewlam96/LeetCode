//Time Complexity O(n)
//Spce Complexity O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        //go through vector
        for(int j = 0; j < nums.size(); ++j){
            //if the number is not the value move it to the beginning of the list
            if(nums[j] != val){
                nums[i] = nums[j];
                ++i; //increment the position
            }
        }
        return i; //this should be the count value
    }
};