//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot, left = 0, right = nums.size() - 1;
        
        //keep splitting up space until it is the same
        while (left <= right) { 
          pivot = left + (right - left) / 2; //get middle point
          if (nums[pivot] == target) return pivot; //if found return value
          //check if value is less than pivot number (can also check greater but would need to do opposite then)
          //if it is less update right side 
          if (target < nums[pivot]) right = pivot - 1; 
          else left = pivot + 1; //otherwise update left side
        }
        return -1;
    }
};