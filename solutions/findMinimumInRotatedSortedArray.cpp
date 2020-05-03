//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX; //set min as max int

        //go through vector
        for(auto &i : nums){
            //if number is smaller set it as min
            if(i < min) min = i;
        }
        return min;
    }
};

//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, pivot;
        
        while(left < right){
            //get pivot point
            pivot = left + (right - left) / 2;
            
            //if the pivot value is smaller than right value than it is in order
            //so we get right to pivot point (note that it is important to get as pivot not pivot -1)
            if(nums[pivot] < nums[right]) right = pivot;
            //otherwise we want to set left as pivot + 1 since it's on right side
            else left = pivot + 1;
        }
        return nums[left];
    }
};