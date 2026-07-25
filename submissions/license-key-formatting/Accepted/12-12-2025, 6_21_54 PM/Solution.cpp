// https://leetcode.com/problems/license-key-formatting

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        string result = "";
        int count = 0;

        for(int i = n-1 ; i>=0 ; i--)
        {
            if(s[i] == '-') continue;
            result.push_back(toupper(s[i]));
            count++;

            if(count == k)
            {
                result.push_back('-');
                count = 0;
            }
        }
        if(!result.empty() and result.back() == '-') result.pop_back();
        reverse(result.begin() , result.end());
        return result;
    }
};