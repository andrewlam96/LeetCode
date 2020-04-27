//Time Complexity O(n) (it is not O(n^2) since we go through each string but separely, we go through each string n times)
//Space Complexity O(n)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain; //map to contain word and frequency count
        vector<string> solution; //vector to put output solution

        //want to go through every string
        for(auto &s: cpdomains){

            //use a stringstream so we can manipulate input
            stringstream ss(s);
            int num;
            string word;
            
            //extract number and the entire string
            ss >> num >> word;

            //use string as key and amount as value
            //we want to usue += because we want to add to the value if it already exists
            domain[word] += num;
            
            //now we want to get every word after the .
            //go through the entire string
            for(int i = 0; i <= word.size(); ++i){
                //search for a '.' in string
                //we want everything after the . so we add it to our map 
                //use i+1 because i is . so + 1 is after it. Then go until the end.
                if(word[i] == '.') domain[word.substr(i+1, word.size() - 1)] += num;
            }
        }
        
        //Now our map is filled and we ant the extract the data
        //go through map and push back first the value (need to convert to string) and then the key
        for(auto &d : domain){
            solution.push_back(to_string(d.second) + " " + d.first);
        }
        return solution;
    }
};