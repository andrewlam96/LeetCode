//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //initial checks
        if(nums.size() == 0) return -1; //if empty return -1
        if(nums[0] == target) return 0; //if first or only number return first index
        
        int pivot, left = 0, right = nums.size() - 1;
        
        while(left <= right){
            pivot = left + (right - left) / 2; //find middle point
            if(nums[pivot] == target) return pivot; //if found return index
            
            //Next find out which side is sorted correctly
            //i.e. 3 5 6 0 1 2 3 right side is sorted so we don't do binary search using left side conditions
            //I chose to check left side 
            if(nums[left] <= nums[pivot]){ //important to check <= (or >= if doing right side) because of if left/right == pivot 
                if(nums[left] <= target && nums[pivot] > target) right = pivot - 1; //check if it's between left and middle and if true search left
                else left = pivot + 1; //else make smaller and search right
            }
            else{
                //this means opposite side is true
                if(nums[pivot] < target && nums[right] >= target) left = pivot + 1; //check if it's between middle to right and if true search right
                else right = pivot - 1; //else search left
            }
        }
        return -1;
    }
};