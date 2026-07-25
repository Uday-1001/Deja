// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string , int>mp;

        string str = s.substr(0 , k);
        mp[str]++;

        for(int i = k ; i<s.size() ; i++)
        {
            char to_add = s[i];

            str += to_add;
            str.erase(0 , 1);

            mp[str]++;
        }

        return mp.size() == (pow(2 , k));
    }
};