// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int n) {
        string ans = "";
        if(n == 0) return "0";
        int num = abs(n);
        
        while(num > 0)
        {
            ans.push_back((num % 7)+ '0');
            num /= 7;
        }
        reverse(ans.begin() , ans.end());
        if(n < 0) ans = '-' + ans;
        return ans;
    }
};