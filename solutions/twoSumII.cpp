//Input array is sorted
//Time Complexity O(n)
//Space Complexity O(1) //technically since we only need space for 2 ints 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //get the two indices (beginning and end)
        int left = 0, right = numbers.size() - 1;
        //want to keep going until the indices meet
        while(left < right){
            //get the sum of the two numbers
            int sum = numbers[left] + numbers[right];
            
            //if the sum == target we want to return a vector of the two indices
            if(sum == target) return vector<int> {left + 1, right + 1};

            //if it is too big move the right index back
            else if(sum > target) --right;

            //otherwise sum is too small so move the left index to the right
            else ++left;
        }
        return vector<int>();
    }
};