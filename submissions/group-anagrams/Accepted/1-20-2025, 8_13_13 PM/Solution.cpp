// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    static std::array<int , 26> hash (string &s)
    {
        std:: array<int , 26> hash = {0};
        for(int i=0 ; i<s.size() ; i++)
        {
            hash[s[i] - 'a']++;
        }
    return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,26> , vector<string>> mapping;
        for(auto str : strs)
        {
            mapping[hash(str)].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(auto it : mapping)
        {
            ans.push_back(it.second);
        }
    return ans ;
    }
};