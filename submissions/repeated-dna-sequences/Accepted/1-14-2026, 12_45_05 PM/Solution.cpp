// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string , int>mp;
        if(s.size() < 10) return ans;

        string curr = s.substr(0 , 10);
        mp[curr]++;

        for(int i = 10 ; i < s.size() ; i++)
        {
            char ch = s[i];
            curr.erase(0 , 1);
            curr = curr + ch;

            mp[curr]++;
        }
        for(auto it : mp)
        {
            if(it.second >= 2) ans.push_back(it.first);
        }
        return ans;
    }
};