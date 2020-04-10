//Solution 1: Using a map (better time complexity)
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        //use map where key is the number and value is the total times it is in vector
        unordered_map<int, int> myMap;
        //first loop puts all numbers and how many times it is found in map
        for(auto &a : arr){
            myMap[a]++;
        }
        //second loop counts the elements
        for(auto &a: arr){
            auto it = myMap.find(a+1); //search for the number + 1 (i.e. if a is 1 we look for 2)
            if(it != myMap.end()) ++count; //if found, we add to count 
        }
        return count;
    }
};

//Solution 2: Sorting and counting (better space complexity)
//Time Complexity O(n log n)
//Space Complexity O(1)
class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        int totalNumbers = 1; //keeps count of the total number of times the same number occurs
        sort(arr.begin(), arr.end()); //sort the vector so we can do our checking in order
        for(int i = 1; i < arr.size(); ++i){ //start at 1 since we want to check the element before
            //check if numbers are same or not
            if(arr[i - 1] != arr[i]){ //if not, go into if statement
                if(arr[i - 1] + 1 == arr[i]) count += totalNumbers; //then check if the number after is 1 more and if is add total numbers to count
                totalNumbers = 0; //reset total numbers
            }
            ++totalNumbers; //always add to total number after our checks
        }
        return count;
    }
};