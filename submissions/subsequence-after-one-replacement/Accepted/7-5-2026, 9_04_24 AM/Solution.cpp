// https://leetcode.com/problems/subsequence-after-one-replacement

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int>pref(n+1 , -1);
        pref[0] = 0;
        int j = 0;

        for(int i = 0 ; i<n ; i++){
            if(pref[i] == -1) break;
            while(j<m and s[i] != t[j]) j++;
            if(j < m){
                pref[i+1] = j+1;
                j++;
            }
            else pref[i+1] = -1;
        }

        vector<int>suff(n+1 , -1);
        suff[n] = m;
        j = m-1;

        for(int i = n-1 ; i>=0 ; i--){
            if(suff[i+1] == -1) break;
            while(j>=0 and s[i] != t[j]) j--;
            if(j >= 0){
                suff[i] = j;
                j--;
            }
            else suff[i] = -1;
        }

        if(pref[n] != -1) return true;

        for(int i = 0 ; i<n ; i++){
            if(pref[i] == -1) break;
            if(pref[i] >= m) continue;
            if(suff[i+1] == -1) continue;
            if(pref[i] + 1 <= suff[i+1]) return true;
        }
        return false;
    }
};