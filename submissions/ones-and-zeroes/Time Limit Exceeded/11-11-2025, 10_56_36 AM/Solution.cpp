// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    static bool mycomp(string &a , string &b)
    {
        return a.size() < b.size();
    }

    pair<int,int> countDigits(string &a)
    {
        int zeros = 0;
        int ones = 0;
        for(auto ch : a)
        {
            if(ch == '0') zeros++;
            else ones++;
        }
        return {zeros , ones};
    }

    int byrec(vector<string>&strs , int m , int n , int i)
    {
        if(i >= strs.size()) return 0;

        string str = strs[i];
        auto[zero_count , one_count] = countDigits(str);

        int include = 0;
        if(m - zero_count >= 0 and n - one_count >= 0)
        {
            include = 1 + byrec(strs , m - zero_count , n - one_count , i+1);
        }
        int exclude = 0 + byrec(strs , m , n , i+1);
        return max(include, exclude);   
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        sort(strs.begin() , strs.end() , mycomp);
        
        return byrec(strs , m , n , 0);
    }
};