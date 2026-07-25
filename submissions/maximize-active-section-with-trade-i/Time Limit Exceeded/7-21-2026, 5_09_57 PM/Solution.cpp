// https://leetcode.com/problems/maximize-active-section-with-trade-i

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int>leftzeros(n), rightzeros(n);
        int ones = s[0] == '1' ? 1 : 0;

        leftzeros[0] = (s[0] == '0') ? 1 : 0;
        rightzeros[n-1] = (s[n-1] == '0') ? 1 : 0;

        for(int i = 1 ; i < n ; i++) 
        {
            if(s[i] == '1') ones++;
            leftzeros[i] = (s[i] == '0') ? leftzeros[i-1] + 1 : 0;
        }

        for(int i = n-2 ; i >= 0 ; i--) rightzeros[i] = (s[i] == '0') ? rightzeros[i+1] + 1 : 0;

        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {   
            if(s[i] == '1')
            {
                int j = i;
                while(j < n and s[j] == '1') j++;

                if(i > 0 and j < n and leftzeros[i-1] > 0 and rightzeros[j] > 0) 
                    ans = max(ans , leftzeros[i-1] + rightzeros[j]);
            }
        }

        return ans + ones;
    }
};