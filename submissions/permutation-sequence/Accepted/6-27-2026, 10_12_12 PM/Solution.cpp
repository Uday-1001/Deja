// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    string ans;
    int factorial(int n)
    {
        int fact = 1;
        for(int i = 2 ; i<= n ; i++) fact *= i;
        return fact;
    }

    void solve(int n , int k , int fact_val , int partsize , string &number)
    {
        if(n == 0) return;

        int index = k / partsize;
        char req_digit = number[index];
        ans.push_back(req_digit);

        number.erase(begin(number) + index);

        int newk = k % partsize;
        int newpartsize = (n == 1) ? 1 : factorial(n-2);

        solve(n-1 , newk , fact_val , newpartsize , number);
    }

    string getPermutation(int n, int k) {
        int fact_val = 1;

        string number = "";
        for(int i = 1 ; i <=n ; i++)
        {
            fact_val *= i;
            number.push_back(i + '0');
        }
        ans = "";
        int partsize = fact_val / n;
        k--;

        solve(n , k , fact_val , partsize , number);
        return ans;
    }
};