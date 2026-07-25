// https://leetcode.com/problems/largest-even-number

class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        vector<string>pref(n);
        pref[0] = s[0];

        for(int i = 1 ; i < n ; i++) pref[i] = pref[i-1] + s[i];

        for(auto it : pref) cout<<it<<" ";
        string ans = "";
        for(int i = 0; i < n ; i++)
        {

        }
    return ans; 
    }
};