//Time Complexity O(n log n) because gcd takes n log n
//Space Complexity O(n) 
class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression); //convert to stringstream to get data as ints
        //need 4 variables
        //formula for ((a / b) + (c / d)) = (((a * d) + (c * b)) / (b * d)) 
        int a = 0, b = 1, c, d;
        char ch; //character to read in '/'
        //input is read by each fraction, so int >> char >> int
        //i.e. -1/2+1/2 is -1(int) /(char) 2(int) then it will loop again and read +1(int) /(char) 2(int)
        while (ss >> c >> ch >> d) {
            //next 2 lines are part of the forumla described above
            a = a * d + c * b; 
            b = b * d;
            //next find gcd to get smallest numbers
            //can use __gcd() or in C++17 gcd()
            int g = gcd(a, b);
            //make a and b smaller by the gcd
            a /= g; 
            b /= g;
        }
        return to_string(a) + '/' + to_string(b); //return as string
    }
};
