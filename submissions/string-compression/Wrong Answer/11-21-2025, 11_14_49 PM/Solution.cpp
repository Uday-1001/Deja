// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        map<char,int>mp;
        string ans;
        for(auto ch : chars) mp[ch]++;

        for(auto it : mp)
        {
            char character = it.first;
            int freq = it.second;

            ans.push_back(character);

            string freqstr = to_string(freq);

            ans += freqstr;
        }
        return ans.size();
    }
};