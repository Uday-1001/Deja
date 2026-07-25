// https://leetcode.com/problems/group-anagrams

class Solution {
public:
        std::array<int,26>hash (string &s)
        {
            std::array<int , 26> hash = {0};
            for(int i =0 ; i<s.size() ; i++)
            {
                hash[s[i] - 'a']++;
            }
            return hash;
        }
    vector<vector<string>> groupAnagrams(vector<string>&s) {
        map<std::array<int , 26> , vector<string>>ans ;

        for(int i = 0 ; i<s.size() ; i++)
        {
            ans[hash(s[i])].push_back(s[i]);
        }

        vector<vector<string>>final;
        for(auto str : ans)
        {
            final.push_back(str.second);
        }
    return final;
    }
};