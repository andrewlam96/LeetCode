// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//Solution 1: linear search TIME LIMIT EXCEEDS
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        for(int i = 1; i < n; ++i){ //go from 1 to n
            if(isBadVersion(i)) return i; //if it is true, it must first occurance so return number
        }
        return n; //otherwise return 1 (i.e. if number is 1)
    }
};

//Solution 2: Binary Search 
//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int pivot, left = 1, right = n; //start at 1 and ends at n
        while(left <= right){ //keep making search smaller until left is equal to or greater than right
            pivot = left + (right - left) / 2; // pivot is middle point
            if(isBadVersion(pivot)) right = pivot - 1; //if it is a bad version check left side to see if anything is smaller
            else left = pivot + 1; //otherwise check right side
        }
        
        return left; //return left since it will always be before or the same as right 
    }
};