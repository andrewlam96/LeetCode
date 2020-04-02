//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //i is size - 1 for nums1
        //j is size - 1 for nums2
        //k is the size of nums1 and nums2 -1
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        //we want to keep looping until we run out of elements from BOTH nums1 and nums2
        //The idea is to start backwards and put the greatest number first and work until we reach the smallest
        while(i >= 0 || j >= 0 ){
            //First check if both vectors have elements 
            //It is important to check them first before comparing elements 
            //because if one of them is empty we will get an error if we try to compare an index that isn't there
            //So if both have something, check from end (sorted so greatest is at end) to see which one is larger
            if(i >= 0 && j >= 0 && nums1[i] > nums2[j]){  
                //insert the larger number to end of nums1 and decrement the counters (k-- and i--)
                //important to use k-- not --k because we want to decrement after we're done using it not during/before
                nums1[k--] = nums1[i--]; 
                continue; //skips everything afterwards (important since some conditions can still be true)
            }
            //check if nums2 > nums1 (everything else the same idea from before)
            else if(i >= 0 && j >= 0 && nums1[i] < nums2[j]){
                nums1[k--] = nums2[j--];
                continue;
            }
            //there 2 condiitons are if one vector is not empty but other is
            if(i >= 0) nums1[k--] = nums1[i--]; //if nums1 not empty put the rest in there
            else if(j >= 0) nums1[k--] = nums2[j--]; //otherwise it means nums2 not empty so we add nums2 elements instead 
        }
    }
};