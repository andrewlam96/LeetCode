//Time Complexity O(n)
//Space Complexity O(n)
//sliding window technique

//i.e. word is zyxxz and [] is set
//so [z] left = 0, right = 1 then [zy] left = 0 right = 2 then [zyx] left = 0 right = 3
//then [yx] left = 1 right = 3 then [x] left = 2 right = 3 then [] left = 3 right = 3
//then [x] left = 3 right = 4 finally [xz] left = 3 right = 5(s.size())
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mySet; //set to store characaters

        //maxlen is the max length, left and right are the indices we will traverse with
        int maxLen = 0, left = 0, right = 0; 

        //go until one reaches the end
        while(left < s.size() && right < s.size()){
            //check if set character is NOT in set
            if(mySet.find(s[right]) == mySet.end()){
                //we insert it, increment right
                mySet.insert(s[right++]);

                //then we get the maxlength which is either itself or right - left
                maxLen = max(maxLen, right - left);
            }
            //if it is we want to delete the first letter from set and increment left to next position
            else mySet.erase(s[left++]);
        }
        return maxLen;
    }
};