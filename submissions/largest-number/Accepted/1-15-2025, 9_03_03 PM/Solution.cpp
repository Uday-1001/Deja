// https://leetcode.com/problems/largest-number

class Solution {
public:

    static bool mycomparator(string a , string b)
    {
        string  t1 = a + b ;
        string  t2 = b + a ;
        
        return t1 > t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto it : nums)
        {
            str.push_back(to_string(it));
        }

        sort(str.begin() , str.end() , mycomparator);

        if(str[0] == "0")  return "0";
        string ans = "";
        for(auto st : str)
        {
            ans += st;
        }
    return ans ;
    }
};