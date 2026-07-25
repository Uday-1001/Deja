// https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string

class Solution {
public:
    string binary(int n)
    {
        string ans = "";
        while(n){
            int digit = n % 2;
            ans += digit + '0';
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
    return ans;
    }
    int minimumFlips(int n) {
        string num = binary(n);
        string t = num;
        reverse(num.begin() , num.end());
        string m = num;
        
        int opr = 0;
        int i=0 , j=0;
        while(i < t.size() && j < m.size())
            {
                if(t[i] != m[j])
                {
                    opr++;
                }
                i++;
                j++;
            }
        return opr;
    }
};