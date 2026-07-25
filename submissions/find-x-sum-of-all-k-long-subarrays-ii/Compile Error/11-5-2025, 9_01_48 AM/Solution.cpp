// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii

class Solution {
public:    
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;

        //calculating answer for the first window
        for(int i=0 ; i<k ; i++) mp[nums[i]]++;
        for(auto it : mp) pq.push({it.second , it.first});

        int sum = 0;
        int copy_x = x;
        while(!pq.empty() && copy_x > 0)
        {
            auto[freq , num] = pq.top(); pq.pop();
            sum += num * freq;
            copy_x--;
        }
        ans.push_back(sum);

        //calculating answer for the next windows
        for(int i=k ; i<nums.size(); i++)
        {
            int added = nums[i];
            mp[added]++;

            int removed = nums[i - k];
            mp[removed]--;

            while(!pq.empty()) pq.pop();
            for(auto it : mp) pq.push({it.second , it.first});

            int sum = 0;
            int temp_x = x;
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