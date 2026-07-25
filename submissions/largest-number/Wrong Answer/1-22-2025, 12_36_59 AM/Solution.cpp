// https://leetcode.com/problems/largest-number

class Solution {
public:
    static bool mycomp(string &a , string &b)
    {
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto n : nums)
        {
            ans.push_back(to_string(n));
        }
        sort(ans.begin() , ans.end() , mycomp);

        string final ="";
        for(auto str : ans)
        {
            final += str;
        }
    return final;
    }
};