// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string>> mapping;
        for(auto str : strs)
        {
            string s = str;
            sort(s.begin() , s.end());
            mapping[s].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : mapping)
        {
            ans.push_back(it.second);
        }
    return ans ;
    }
};