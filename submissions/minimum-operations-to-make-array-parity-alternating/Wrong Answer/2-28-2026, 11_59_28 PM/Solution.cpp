// https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0,0};

        int minoprs = INT_MAX;
        int minrange = INT_MAX;

        for(int start = 0 ; start < 2 ; start++)
        {
            int oprs = 0;

            //counting the mismatches here for each even and odd pattern
            for(int i = 0 ; i < n ; i++)
            {
                int target = (i % 2 == 0) ? start : 1 - start;
                if((abs(nums[i]) % 2) != target) oprs++;
            }

            //first just try to decrement nums[i]
            vector<int>temp1 = nums;
            for(int i = 0 ; i < n ; i++)
            {
                int target = (i % 2 == 0) ? start : 1 - start;
                if((abs(temp1[i]) % 2) != target) temp1[i]--;
            }

            int newmax = *max_element(temp1.begin(), temp1.end());
            int newmin = *min_element(temp1.begin(), temp1.end());

            if(oprs < minoprs) 
            {
                minoprs = oprs;
                minrange = newmax - newmin;
            }
            else if(oprs == minoprs) 
            {
                minrange = min(minrange, newmax - newmin);
            }
            
            //then just try to increment nums[i]
            vector<int>temp2 = nums;
            for(int i = 0 ; i < n ; i++)
            {
                int target = (i % 2 == 0) ? start : 1 - start;
                if((abs(temp2[i]) % 2) != target) temp2[i]++;
            }
            
            int newmax2 = *max_element(temp2.begin(), temp2.end());
            int newmin2 = *min_element(temp2.begin(), temp2.end());

            if(oprs < minoprs) 
            {
                minoprs = oprs;
                minrange = newmax2 - newmin2;
            }
            else if(oprs == minoprs) 
            {
                minrange = min(minrange, newmax2 - newmin2);
            }
        }
        return {minoprs, minrange};
    }
};