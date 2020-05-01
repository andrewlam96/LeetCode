//Time complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        //this can be solved mathimatically 
        //formula is 2(2n+1) / (n+2)
        for(int i = 0; i < n; ++i)
            ans = ans * (2) * (2 * i + 1) / (i + 2);
        return ans;
    }
};