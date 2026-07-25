// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hash(26);

        for(auto it : s) hash[it - 'a']++;
        for(auto it : t) hash[it - 'a']--;

        for(auto it : hash) if(it != 0) return false;
        return true;
    }
};