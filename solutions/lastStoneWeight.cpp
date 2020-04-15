//Time Complexity O(n log n)
//Space Complexity O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //want to keep checking until there is at most 1 element in vector
        while(stones.size() > 1){
            sort(stones.begin(), stones.end()); //sort inside of loop because we will still add to vector possibly
            int n = stones.size() - 1; //just easier way to using size - 1 instead of typing it out
            int diff = stones[n] - stones[n-1]; //get the difference between two largest numbers
            
            //always want to delete the two largest numbers 
            //in this case they will always be at end since sorted
            stones.pop_back(); 
            stones.pop_back();
            if(diff != 0) stones.push_back(diff); //if they are not the same we will add the difference to vector
        }
        return stones.empty() ? 0 : stones.front(); //return 0 if empty otherwise return the value of remaining stone
    }
};