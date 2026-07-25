// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string , int>mp;

        string str = "";

        for(int i = 0 ; i<k ; i++) str += s[i];

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