// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int> map;
        for(int i =0 ; i<s.size(); i++)
        {
            map[s[i]]++;
        }
        int possible ;
        int count = 0 ;
        for(auto it : map)
        {
            possible = it.second & 1 ? count++ : 0 ;
        }
            if(count <= k)
            {
                return true;
            }
        return false;
    }
};