// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        string ans = "";
        int carry = 0;

        while(i >= 0 or j >= 0) 
        {
            int digit = carry;  

            if(i >= 0) digit += (a[i--] - '0');
            if(j >= 0) digit += (b[j--] - '0');

            if(digit > 1) 
            {
                digit -= 2;      
                carry = 1;       
            } 
            else carry = 0;

            ans.push_back(digit + '0');
        }

        if(carry > 0) ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
