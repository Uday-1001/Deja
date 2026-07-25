// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 1)
            {
                pq.push({i , nums[i]});
            }
        }
        bool ans = false;
        while(pq.size() > 1)
        {
            auto[index1 , num1] = pq.top(); pq.pop();
            auto[index2 , num2] = pq.top();

            if((index2 - index1 - 1) >= k) 
                ans = true;
            else 
                ans = false;
        }
        return ans;
    }
};