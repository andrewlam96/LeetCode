//Time Complexity O(n log n)
//Space Complexity O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end()); //sort the vector so that numbers will be in order
        int total = 0, need = 0; //total is the amount of moves and need is what the number needs to at least be
        for (int &a: A) { // go through vector
            //add to the total of what the need - current value is (or 0 because in beginnning need-a will be negative)
            total += max(need - a, 0);
            //need is what the next number + 1 should be
            //i.e. 1 2 3 need = 2 because the next number needs to be at least 2 then need = 3 etc..
            //another ex. 1 3 3 4 need = 2 then need = 4 (a + 1) then need = 5 (need + 1) then need = 6 (need + 1)
            need = max(a, need)+1;
        }
        return total;
    }
};