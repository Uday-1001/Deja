// https://leetcode.com/problems/weighted-word-mapping

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int , int>mp;
        for(int i = 0 ; i<26 ; i++) mp[i + 'a'] = weights[i];

        string ans = "";

        for(auto it : words)
        {
            int sum = 0;
            for(auto x : it) sum += mp[x];
            sum %= 26;

            ans.push_back('z' - sum);
        }
        return ans;
    }
};