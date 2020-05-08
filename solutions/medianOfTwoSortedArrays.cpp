//Solution 1: Use Vector
//Time Complexity O(m + n)
//Space Complexity O(m + n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> solution;
        
        //cpunters for the two vectors
        int count1 = 0, count2 = 0;

        //want to keep going until we get every number
        while(count1 < nums1.size() || count2 < nums2.size()){
            //if both numbers are valid
            if(count1 < nums1.size() && count2 < nums2.size()){
                //check if the first is less than the second
                if(nums1[count1] <= nums2[count2]){
                    //if it is, add it to vector and increment the count
                    solution.push_back(nums1[count1]);
                    ++count1;
                }
                //otherwise do the same thing but for nums2
                else{
                    solution.push_back(nums2[count2]);
                    ++count2;
                }
            }
            //then these two conditions do the same thing 
            //but only run if one of the vectors has reached the end
            else if(count1 < nums1.size()){
                solution.push_back(nums1[count1]);
                ++count1;
            }
            else if(count2 < nums2.size()){
                solution.push_back(nums2[count2]);
                ++count2;
            }
        }
        
        //finally to get the result
        //there are 2 conditions
        //if odd size number then return the middle
        //otherwise return the middle and the one before divided by 2
        int sz = solution.size();
        if(sz % 2 == 1) return (double) solution[sz / 2];
        else return (solution[sz / 2] + solution[sz / 2 - 1]) / 2.0;
    }
};

//Solution 2: No vector (only use half of the values)
//Time Complexity O(m + n)
//Space Complexity O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //idea is similar as solution 1
        //except we just go through half the lists and return middle

        //counts for indicies
        //prev and curr for current and previous number (will be median eventtually) 
        //total is total size of nums1 and nums2 and mid will be counter until we reach half way
        int count1 = 0, count2 = 0, prev, curr, mid = 0;
        int total = nums1.size() + nums2.size();
        
        while(count1 < nums1.size() || count2 < nums2.size()){
            //check if both still have values left
            if(count1 < nums1.size() && count2 < nums2.size()){
                //if nums1 < nums2
                if(nums1[count1] <= nums2[count2]){
                    //set curr to that number
                    //then increment counter for nums1
                    curr = nums1[count1];
                    ++count1;
                }
                //same idea but for nums2
                else{
                    curr = nums2[count2];
                    ++count2;
                }
            }
            //if either num1 or nums2 is empty and still need to keep going run either else ifs
            else if(count1 < nums1.size()){
                curr = nums1[count1];
                ++count1;
            }
            else if(count2 < nums2.size()){
                curr = nums2[count2];
                ++count2;
            }
            
            //if middle is reached break out of loop
            if(mid == total / 2) break;
            
            //set prev to curr
            //and increment closer to middle
            prev = curr;
            ++mid;
            
        }
        //if the total size is odd return the current number
        //otherwise add the previous and current number and divide them by 2
        if(total % 2 == 1) return (double) curr;
        else return (prev + curr) / 2.0;
    }
};

//Solution 3: Use a modified binary search
//Time Complexity O(log(min(m,n)))
//Space Complexity O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //size of two arrays
        int m = nums1.size(), n = nums2.size();
        
        //we want first vector to be smaller so
        //if it is larger
        //we swap the vectors
        //as well as their size variables i made earlier
        if(m > n){
            nums1.swap(nums2);
            swap(m,n);
        }
        
        //iMin is beginning of "m" and iMax is end of "m"
        //mid is the size of both sizes added by 1 dividied by 2
        //this is to help with getting mid point for 2nd array 
        int iMin = 0, iMax = m, mid = (m + n + 1) / 2;
        while(iMin <= iMax){
            //i be midpoint for 1st vec while j will be midpoint for 2nd vec
            //just get the middle from the ends / 2 for 1st vec
            //for j, we want the middle - i 
            int i = (iMin + iMax) / 2;
            int j = mid - i;

            //idea is we want to divide the two arrays up into halves where the middle - 1 for both is less than middle of the opposite
            //i.e. 1 2 3   4 5 6
            //     2 3 5   6 8 9
            //we want 3 < 6 and 5 < 4

            //so if 2nd vec mid-1 is greater than first vec mid then we move the first vec to right
            //the opposite happens when 1st vec mid-1 greater than 2nd vec mid (we move to the left)
            if(i < iMax && nums2[j - 1] > nums1[i]){
                iMin = i + 1;
            }
            else if(i > iMin && nums1[i - 1] > nums2[j]){
                iMax = i - 1;
            }
            //this means we found our perfect indexing so we can now get answer
            else{
                int maxLeft = 0; 
                //if either index is at the beginning then nothing can be to the "left" of it
                //therefore the max has to be the opposite - 1 
                //otherwise we just get the max of the two mid points
                if(i == 0) maxLeft = nums2[j - 1];
                else if(j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);
                
                //if the size is odd, we return that max we just found
                if((m + n) % 2 == 1) return maxLeft;
                
                //if the size is even we also have to find the minimum of the two "right" values
                //again if the index is at the end, then it had to be the opposite mid point
                //otherwise we find the minimum of the two "right" values
                int minRight = 0;
                if(i == m) minRight = nums2[j];
                else if(j == n) minRight = nums1[i];
                else minRight = min(nums2[j], nums1[i]);
                
                //the answer is just then the average of the two values added divided by 2.0 (for double division)
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};