// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string , vector<string>>mp;

        for(auto word : strs)
        {
            string copy = word;
            sort(begin(copy) , end(copy));
            mp[copy].push_back(word);
        }

        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};