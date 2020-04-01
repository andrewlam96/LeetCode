/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
//Time Complexity O(log n)
//Space Complexity O(1)
class Solution {
public:
    int guessNumber(int n) {
        //number is from 1 to n so left is 1 and right is n
        int pivot, left = 1, right = n; 
        
        while(left <= right){
            pivot = left + (right - left) / 2; //pivot is middle point
            if(guess(pivot) == 0) return pivot; //0 means correct so return pivot if true
            else if(guess(pivot) == 1) left = pivot + 1; //1 means higher so move left to pivot + 1 to check numbers higher
            else right = pivot - 1; //otherwise it should be -1 which means lower so move right to pivot - 1
        }
        return pivot;
    }
};