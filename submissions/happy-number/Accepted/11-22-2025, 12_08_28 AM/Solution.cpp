// https://leetcode.com/problems/happy-number

class Solution {
public:
    int sumSq(int n) 
    {
        int sum = 0;
        while(n) 
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while(!seen.count(n)) 
        {
            seen.insert(n);
            n = sumSq(n);
            if(n == 1) return true;
        }
        return false; 
    }
};