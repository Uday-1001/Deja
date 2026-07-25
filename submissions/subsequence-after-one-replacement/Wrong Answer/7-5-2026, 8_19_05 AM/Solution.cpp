// https://leetcode.com/problems/subsequence-after-one-replacement

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<int>pref(m+1 , 0);
        vector<int>suff(m+1 , 0);

        int i = 0;
        for(int j = 0 ; j<m ; j++){
            if(i < n and s[i] == t[j]) i++;
            pref[j+1] = i;
        }

        i = n-1;
        for(int j = m-1 ; j >= 0 ; j--){
            if(i >= 0 and s[i] == t[j]) i--;
            suff[j] = n-i-1;
        }

        for(int j = 0 ; j<=m ; j++){
            int left = pref[j];
            int right = (j == m ? 0 : suff[j]);

            if(left + right >= n-1) return true;
        }
        return false;
        
    }
};