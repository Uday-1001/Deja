// https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(2);
        if(n == 1)
        {
            ans[0] = 0;
            ans[1] = 0;
            return ans;
        }

        int minoprs = INT_MAX;
        int minval = INT_MAX;

        for(int start = 0 ; start < 2 ; start++)
        {
            int oprs = 0;
            vector<int>temp = nums;
            int maxi = *max_element(temp.begin() , temp.end());
            int mini = *min_element(temp.begin() , temp.end());

            for(int i = 0 ; i<n ; i++)
            {
                int ongoingparity = (i % 2 == 0) ? start : 1 - start;
                if((abs(temp[i]) % 2) != ongoingparity)
                {
                    if(abs(temp[i] - maxi) < abs(temp[i] - mini))
                    {
                        temp[i]--;
                    }
                    else temp[i]++;
                    oprs++;
                }
            }
            int newmaxi = *max_element(temp.begin() , temp.end());
            int newmini = *min_element(temp.begin() , temp.end());

            if(oprs < minoprs)
            {
                minoprs = oprs;
                minval = newmaxi - newmini;
            }
            else if(oprs == minoprs)
            {
                minval = min(minval , newmaxi - newmini);
            }
        }
    ans[0] = minoprs;
    ans[1] = minval;
    return ans;
    }
};