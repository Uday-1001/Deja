// https://leetcode.com/problems/sum-of-distances

class Solution {
public:
    using ll = long long; 
    vector<long long> distance(vector<int>& nums) {
        unordered_map<ll , vector<ll>>mp;

        for(int i = 0 ; i<nums.size() ; i++) mp[nums[i]].push_back(i);

        for(auto it : mp)
        {
            cout<<it.first<<"->";
            for(auto x : it.second) cout<<x<<",";
            cout<<endl;
        }

        vector<long long>ans(nums.size() , 0);
        for(auto it : mp)
        {
            if(it.second.size() == 1) continue;

            for(int i = 0 ; i<it.second.size() ; i++)
            {
                int dist = 0;
                for(int j = 0 ; j<it.second.size() ; j++)
                {
                    if(i == j) continue;
                    dist += abs(it.second[i] - it.second[j]);
                }
                ans[it.second[i]] = dist;
            }
        }
        return ans;
    }
};