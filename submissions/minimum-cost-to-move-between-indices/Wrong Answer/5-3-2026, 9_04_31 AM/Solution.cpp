// https://leetcode.com/problems/minimum-cost-to-move-between-indices

class Solution {
public:
    using ll = long long;
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>ans;
        vector<ll>leftcost(n , 0);
        vector<ll>rightcost(n , 0);

        for(int i = 0 ; i<n-1 ; i++){
            ll cost = 0;
            if(i == 0) cost = 1;
            else {
                ll leftdist = (ll)nums[i] - nums[i-1];
                ll rightdist = (ll)nums[i+1] - nums[i];

                if(rightdist < leftdist) cost = 1;
                else cost = rightdist;
            }
            rightcost[i+1] = rightcost[i] + cost;
        }
        

        for(auto it : leftcost) cout<<it<<" ";
        cout<<endl;
        for(auto it : rightcost) cout<<it<<" ";

        return ans;
        
        
    }
};