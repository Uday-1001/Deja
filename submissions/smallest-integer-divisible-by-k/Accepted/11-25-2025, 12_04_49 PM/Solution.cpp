// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 or k % 5 == 0) return -1;
        int rem_val = 1 % k;
        if(rem_val == 0) return 1;
        int size = 1;

        while(true)
        {
            string rem = to_string(rem_val);    
            string num_to_divide = rem + '1';
            int n = stoi(num_to_divide);
            if(n % k == 0)
            {
                size++;
                break;
            } 
            else
            {
                rem_val = n % k;
                size++;
            } 
        }
    return size;
    }
};