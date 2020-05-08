//Time Complexity O(1)
//Space Complexity O(1)
class Solution {
public:
    int bitwiseComplement(int N) {
        //if 0 return 1
        if(N == 0) return 1;
        //we want number of all 1s
        unsigned int mask = ~0;
        
        //we check if both numbers have a 1 in binary position
        //i.e. mask is 11111111 and num is 00000101
        //checks last position first 
        //since both are 1 we left shfit mask once
        //so mask is now 111111110 (multipled by 2) 
        while(mask & N) mask <<= 1;

        //from top example we get something like 11111100 for mask
        //so we want opposite of both and and then
        //mask 11111100
        //num  00000101 (5)
        //~mask 00000011
        //~num  11111010 
        //ans   00000010 (2) which is complement
        return ~mask & ~N;
    }
};