// https://leetcode.com/problems/find-the-smallest-balanced-index

class Solution {
public:
    using ll = long long;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<double>suff(n , 1.0);
        for(int i = n-2 ; i>=0 ; i--)
        {
            suff[i] = min(1e15 , suff[i+1] * nums[i+1]);
        }

        ll ls = 0;
        for(int i=0 ; i<n ; i++)
        {
            ll right = suff[i];
            if(ls == right) return i;
            ls += nums[i];
        }
    return -1;
    }
};