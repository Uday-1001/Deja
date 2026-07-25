// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii

class Solution {
public:     
    typedef long long ll;
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<ll,ll>mp;
        priority_queue<pair<ll , ll>>pq;
        unordered_set<ll>st_max_freq;
        vector<ll>ans;

        //calculating answer for the first window
        for(int i=0 ; i<k ; i++) mp[nums[i]]++;
        for(auto it : mp) pq.push({it.second , it.first});

        ll sum = 0;
        ll copy_x = x;
        while(!pq.empty() && copy_x > 0)
        {
            auto[freq , num] = pq.top(); pq.pop();
            st_max_freq.insert(num);
            sum += num * freq;
            copy_x--;
        }
        ans.push_back(sum);
        for(auto it : st_max_freq)
        {
            cout<<*it<<" "; 
        }

        //calculating answer for the next windows
        for(int i=k ; i<nums.size(); i++)
        {
            ll added = nums[i];
            mp[added]++;

            ll removed = nums[i - k];
            mp[removed]--;

            while(!pq.empty()) pq.pop();
            for(auto it : mp) pq.push({it.second , it.first});

            ll sum = 0;
            ll temp_x = x;
            while(!pq.empty() && temp_x > 0)
            {
                auto[freq , num] = pq.top(); pq.pop();
                sum += num * freq;
                temp_x--;
            }
            ans.push_back(sum);   
        }
        if(ans.size() != n-k+1) ans.resize(n-k+1);
        return ans;    
    }
};