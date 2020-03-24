//Solution 1: using bitset
//Time complexity O(1)
//Space complexity O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bit = n;
        return bit.count();
    }
};

//Solution 2: using hammingWeight
//Time Compelxity O(1)
//Space Complexity O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n &= n-1; //flips bit if there is a 1 (i.e. 1 & 0 = 0)
            ++count;
        }
        return count;
    }
};
