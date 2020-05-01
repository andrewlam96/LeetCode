//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        //keep track of the total shifts we have to move
        //also we can make the shifts smaller if theres a lot (i.e. size = 5 keep shifts from 0-5)
        int totalShift = 0, modShift = 0; 
        string s1 = ""; //our solution string
        //go through vector of shifts
        for(int i = 0; i < shift.size(); ++i){
            //the inside vector is always 2 numbers (0/1 for left/right) and (how many times to shift)
            //if first index is 1, add to totalshift the second index (total time for that shift)
            //otherwise do same thing but subtract 
            if(shift[i][0]) totalShift += shift[i][1];
            else totalShift -= shift[i][1];
        }

        //check totalshift
        //0 means no shift, > 0 means right shift, < 0 means left shift
        if(totalShift == 0) return s;
        else if(totalShift > 0){
            //we want to mod by the size to get the how many times to shift
            //i.e. totalshift = 12, size = 5. We can just shift 2 times instead of 12
            modShift = totalShift % s.size();
        }
        else{
            //for left shift, we first want to change our number from negative to positive
            //Then to get the shift, it is similar to positive except we want difference from size
            //i.e. a right shift of 3 from size of 10 is a left shift of 7
            totalShift *= -1;
            modShift = s.size() - totalShift % s.size();
        }
        //we return the string from the point we want the first letter to go to and then everything before that
        //so "abcde" shift 2 right (modshift is 2) we want "de" first then "abc"
        //to get that, we use size - modshift then 0 (beginning) to that point for the things before
        s1 = s.substr(s.size() - modShift) + s.substr(0, s.size() - modShift);
        return s1;
    }
};