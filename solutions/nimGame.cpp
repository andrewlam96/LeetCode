//Time Complexity O(1)
//Space Complexity O(1)

//since you can remove 1-3 stones, any combination can win except when there is a stone amount that is multiple of 4
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};