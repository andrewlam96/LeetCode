//Solution 1: Brute Force (Time Limit Exceeds)
//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int smallest, dist;
        //want to go through all elements
        for(int i = 0; i < height.size(); ++i){
            //want to go through everything after ith element
            for(int j = i + 1; j < height.size(); ++j){
                //set smallest to smallest of the two heights
                //set distance as the difference between j and i
                smallest = min(height[j], height[i]);
                dist = j - i;

                //the max area is either itself if smallest * dist
                maxArea = max(maxArea, smallest * dist);
            }
        }
        return maxArea;
    }
};

//Solution 2: 2 pointer
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        //have two pointers at beginning and end
        int maxArea = 0, left = 0, right = height.size() - 1;
        int dist, smallest;

        //want to keep going until they meet
        while(left < right){
            //set smallest to smallest of two heights
            //set distance as difference between right and left
            dist = right - left;
            smallest = min(height[left], height[right]);

            //area is either itself or smallest * dist
            maxArea = max(maxArea, smallest * dist);

            //we want the biggest height, so compare them
            //if right is smaller we move left and if left is smaller we move right
            if(height[left] < height[right]) ++left;
            else --right;
        }
        return maxArea;
    }
};