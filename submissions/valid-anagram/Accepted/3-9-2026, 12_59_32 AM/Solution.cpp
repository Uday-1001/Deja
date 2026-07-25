// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hash(26 , 0);
        if(s.size() != t.size()) return false;

        for(auto it : s) hash[it - 'a']++;
        for(auto it : t) hash[it - 'a']--;

        for(int i = 0 ; i<hash.size() ; i++){
            if(hash[i] > 0) return false;
        }
    return true;
    }
};