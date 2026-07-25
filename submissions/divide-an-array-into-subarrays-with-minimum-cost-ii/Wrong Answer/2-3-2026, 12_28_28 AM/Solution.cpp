// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii

class Solution {
public:
    using ll = long long;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        ll cost = nums[0];
        int need = k-2;
        ll mincost = LLONG_MAX;

        priority_queue<ll , vector<ll> , greater<ll>>pq;
        for(int i = 1 ; i<nums.size()-1; i++)
        {
            int second_elem = nums[i];
            for(int j = 0 ; j<dist ; j++)
            {
                if(j + i + 1 < n) pq.push(nums[j + i + 1]);
            }
            ll sumofnext = 0;
            sumofnext += second_elem;
            int req = need;
            while(req--)
            {
                sumofnext += pq.top(); 
                pq.pop();
            }
            if(sumofnext + cost < mincost)
            {
                mincost = sumofnext + cost;
            }
        }
        return mincost;
    }
};