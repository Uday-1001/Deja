// https://leetcode.com/problems/maximum-alternating-sum-of-squares

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int , vector<int> , greater<int>>pq;
        int n = nums.size();
        unsigned long long sq_sum = 0;
        long long minuses = n/2;

        for(auto it : nums) 
        {
            pq.push(it*it);
            sq_sum += (unsigned long long)it*it;
        }

        while(!pq.empty() && minuses>0)
        {
            int top = pq.top(); pq.pop();
            sq_sum -= 2ULL*top;
            minuses--;
        }
        return sq_sum;
    }
};