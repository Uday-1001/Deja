// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<pair<int,int>>mp;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>ans;

        for(auto &num : nums)
        {
            mp[num]++;
        }

        for(auto it : mp)
        {
            auto[num , freq] = elem;
            pq.push({freq , num});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        for(auto it : pq)
        {
            auto[freq , num] = it;
            ans.push_back(num);
        }

        return ans;


        
        
        
    }
};