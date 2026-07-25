// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int uniqueElements(int first , int last , string &s)
    {
        unordered_set<char>st(26);
        for(int i = first+1 ; i<last ; i++)
        {
            st.insert(s[i]);
        }
        return st.size();
    }

    int countPalindromicSubsequence(string s) {
        unordered_map<char , pair<int,int>>mp;
        int palins = 0;

        vector<int>first(26, -1), last(26, -1);
        for(int i = 0; i < s.size(); i++) 
        {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }

        for(char ch = 'a' ; ch <= 'z' ; ch++)
        {
            int index = ch - 'a';
            if(first[index] != -1)
            {
                mp[index] = {first[index] , last[index]};
            }
        }

        for(auto it : mp)
        {
            auto[first , last] = it.second;
            if(last > first+1)
            {
                int unique_elem = uniqueElements(first , last , s);
                palins += unique_elem;
            }
        }
    return palins;
    }
};