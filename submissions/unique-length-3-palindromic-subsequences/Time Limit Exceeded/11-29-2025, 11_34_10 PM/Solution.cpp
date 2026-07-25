// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    pair<int,int> getfirstAndlastocc(string &s , char ch)
    {
        int first = s.find(ch);
        int last = s.rfind(ch);

        return {first , last};
    }

    int uniqueElements(int first , int last , string &s)
    {
        unordered_set<char>st;
        for(int i = first+1 ; i<last ; i++)
        {
            st.insert(s[i]);
        }
        return st.size();
    }

    int countPalindromicSubsequence(string s) {
        unordered_map<char , pair<int,int>>mp;
        int palins = 0;

        for(int i=0 ; i<s.size() ; i++)
        {   
            pair<int,int> pair = getfirstAndlastocc(s , s[i]);
            mp[s[i]] = pair;
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