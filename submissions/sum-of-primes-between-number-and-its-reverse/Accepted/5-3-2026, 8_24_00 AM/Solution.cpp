// https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse

class Solution {
public:
    bool isPrime(int num){
        if(num <= 1) return false;
        if(num <= 3) return true;

        if(num % 2 == 0 or num % 3 == 0) return false;
        for(int i = 5 ; i*i <= num ; i+=6){
            if((num % i == 0) or (num % (i+2) == 0)) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string r = to_string(n);
        reverse(begin(r) , end(r));
        int rev = stoi(r);

        int maxi = max(rev , n);
        int mini = min(rev , n);

        int sum = 0;
        for(int i = mini ; i<= maxi ; i++){
            if(isPrime(i)){
                sum += i;
            }
        }
        return sum;
    }
};