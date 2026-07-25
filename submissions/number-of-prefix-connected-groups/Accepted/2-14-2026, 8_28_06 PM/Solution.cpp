// https://leetcode.com/problems/number-of-prefix-connected-groups

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string , int>mp;

        for(auto word : words){
            if(word.size() < k) continue;
            string str = word.substr(0 , k);
            mp[str]++;
        }

        int ans = 0;
        for(auto it : mp) if(it.second >= 2) ans++;

        for(auto it : mp) cout<<it.first<<endl;
        return ans;
    }
};