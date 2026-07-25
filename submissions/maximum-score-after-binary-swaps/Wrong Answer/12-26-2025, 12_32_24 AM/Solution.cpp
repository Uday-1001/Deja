// https://leetcode.com/problems/maximum-score-after-binary-swaps

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<long long>pq;
        long long ans = 0;

        for(int i = 0 ; i<nums.size() ; i++) ans += s[i] == '1' ? nums[i] : 0;

        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(s[i] == '1') 
            {
                if(!pq.empty())
                {
                    sum += pq.top();  pq.pop();
                }
                else sum += 0;
            }
            pq.push(nums[i]);
        }
        return max(sum , ans);
    }
};