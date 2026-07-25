// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n , 0);


        if(k == 0) return ans;

        if(k > 0)
        {
            vector<int>pref(n , 0);
            pref[0] = code[0];
            for(int i = 1 ; i<n ; i++) pref[i] = pref[i-1] + code[i];

            for(int i = 0 ; i<n ; i++)
            {
                int right_elem = n-i-1;
                if(right_elem >= k)
                {
                    ans[i] = pref[i+k] - pref[i];
                }
                else 
                {
                    int sumofallright = 0;
                    sumofallright += pref[n-1] - pref[i];
                    int req_elem = k - right_elem;
                    sumofallright += pref[req_elem - 1];
                    ans[i] = sumofallright;
                }
            }
        }
        else if(k < 0)
        {
            reverse(code.begin() , code.end());
            vector<int>pref(n , 0);
            pref[0] = code[0];

            for(int i = 1 ; i<n ; i++) pref[i] = pref[i-1] + code[i];

            for(int i = 0 ; i<n ; i++)
            {
                int right_elem = n-i-1;
                if(right_elem >= abs(k))
                {
                    ans[i] = pref[i+abs(k)] - pref[i];
                }
                else 
                {
                    int sumofallright = 0;
                    sumofallright += pref[n-1] - pref[i];
                    int req_elem = abs(k) - right_elem;
                    sumofallright += pref[req_elem - 1];
                    ans[i] = sumofallright;
                }
            }
            reverse(ans.begin() , ans.end());
        }
        return ans;
    }
};