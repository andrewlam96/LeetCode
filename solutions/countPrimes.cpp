//Sieve of Eratosthenes
//Time Complexity O(n log log n)
//Space Complexity O(1)
class Solution {
public:
    int countPrimes(int n){
        if(n < 2){
            return 0;
        }
        //using a bool array because it is faster than a vector
        bool* isPrime = new bool[n];

        //set everything inside the array to true
        for(int i = 2; i < n; ++i){
            isPrime[i] = true;
        }

        for(int i = 2; i * i < n; ++i){ //start at 2 and check until a number squared is greater than or equal to n
            if(!isPrime[i]) //if it has already been checked no need to do it again
                continue;
            for(int j = i * i; j < n; j += i) //check all multiples of number until it reaches n
                isPrime[j] = false;
        }

        //count which numbers are "true" (prime)
        int count = 0;
        for(int i = 2; i < n; ++i){
            if(isPrime[i])
                count++;
        }
        return count;
    }
};