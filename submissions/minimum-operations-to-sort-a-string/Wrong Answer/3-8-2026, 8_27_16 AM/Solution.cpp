// https://leetcode.com/problems/minimum-operations-to-sort-a-string

class Solution {
public:
    int minOperations(string s) {
        int n =s.size();
        string t = s;
        sort(t.begin() , t.end());

        if(s == t) return 0;
        if(s.size() == 2) return -1;

        char mini = 'z';
        int oprs = 0;
        for(int i = n-1 ; i>=0 ; i--){
            mini = min(mini , s[i]);
            if(s[i] > mini)  oprs++;
        }
        return oprs;
    }
};