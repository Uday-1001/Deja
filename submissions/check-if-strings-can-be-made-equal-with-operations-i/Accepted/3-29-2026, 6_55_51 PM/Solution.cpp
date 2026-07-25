// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int>a(26,0),b(26,0),c(26,0),d(26,0);

        a[s1[0]-'a']++;
        a[s1[2]-'a']++;

        b[s2[0]-'a']++;
        b[s2[2]-'a']++;

        c[s1[1]-'a']++;
        c[s1[3]-'a']++;

        d[s2[1]-'a']++;
        d[s2[3]-'a']++;

        return (a==b and c==d);
    }
};