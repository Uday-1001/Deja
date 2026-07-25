// https://leetcode.com/problems/smallest-number-with-all-set-bits

class Solution {
public:
    string toBinary(int n)
    {
        string ans = "";
        while(n>0)
        {
            int digit = n % 2;
            ans.push_back(digit + '0');
            n /= 2;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    int smallestNumber(int n) {
       string num = toBinary(n);
       int size = num.size();
       
       int zeros = 0;
       for(auto ch : num)
       {
            if(ch == '0') zeros++;
       }

       return (zeros == 0) ? n : pow(2,size)-1;
    }
};