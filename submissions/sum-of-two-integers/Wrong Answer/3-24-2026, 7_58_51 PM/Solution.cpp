// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    string getbinary(int n)
    {
        string ans = "";
        while(n > 0)
        {
            ans += (n % 2) + '0';
            n /= 2;
        }
        reverse(begin(ans) , end(ans));
        return ans;
    }

    int addbinary(string s , string t)
    {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int carry = 0;
        
        int result = 0;
        int base = 1; 

        while(i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            
            if(i >= 0) sum += (s[i--] - '0');
            if(j >= 0) sum += (t[j--] - '0');
            
            int bit = sum % 2;
            carry = sum / 2;
            
            result += bit * base;
            base *= 2;
        }
        return result;
    }

    int solve(int a  , int b)
    {
        string binary_a = getbinary(a);
        string binary_b = getbinary(b);

        int resultant = addbinary(binary_a , binary_b);
        return resultant;
    }
    int getSum(int a, int b) {
        return solve(a , b);
    }
};