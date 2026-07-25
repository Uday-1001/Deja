// https://leetcode.com/problems/maximum-capacity-within-budget

class Solution {
public:
    int byBS(vector<pair<int,int>>&vp , int target , int idx)
    {   
        int s = 0;
        int e = idx - 1;
        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(vp[mid].first < target)
            {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
    }

    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>>vp;

        for(int i = 0 ; i<n ; i++) vp.push_back({costs[i] , capacity[i]});
        sort(vp.begin() , vp.end());

        //building the best capacity array in order to track the best cap. upto a certain index
        vector<int>best_cap(n);
        best_cap[0] = vp[0].second;
        for(int i = 1 ; i<n ; i++)
        {
            best_cap[i] = max(best_cap[i-1] , vp[i].second);
        }

        //max capacity can be of only one machine and hence initialized here..
        int max_cap = INT_MIN;
        for(int i = 0 ; i<vp.size() ; i++)
        {
            if(vp[i].first < budget)
            {
                max_cap = max(max_cap , vp[i].second);
            }
        }

        for(int i = 0 ; i<vp.size() ; i++)
        {
            int second_machine_idx = byBS(vp , budget - vp[i].first , i);
            if(second_machine_idx != -1) 
                max_cap = max(max_cap , (best_cap[second_machine_idx] + vp[i].second)); 
        }
        return max_cap == INT_MIN ? 0 : max_cap;
    }
};