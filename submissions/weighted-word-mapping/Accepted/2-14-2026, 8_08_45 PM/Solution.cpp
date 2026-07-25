// https://leetcode.com/problems/weighted-word-mapping

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char,int>mp;
        for(int i = 0 ; i<26 ; i++) mp['a' + i] = weights[i];
        string ans = "";
        for(auto it : words){
            int sum = 0;
            for(auto ch : it){
                sum += mp[ch];
            }
            int req = sum % 26;
            ans.push_back('z' - req);
        }
    return ans;
        
    }
};