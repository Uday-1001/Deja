// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> SWAndDequeMethod(vector<int>&nums , int k)
    {
        deque<int>dq;
        vector<int>ans;

        for(int i = 0 ; i<k ; i++)
        {
            while(!dq.empty() and nums[i] >= dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        for(int i = k ; i<nums.size() ; i++)
        {
            int to_add = nums[i];

            if(!dq.empty() and(i - dq.front() >= k)) dq.pop_front();

            while(!dq.empty() and to_add >= dq.back()) dq.pop_back();
            dq.push_back(to_add);

            ans.push_back(dq.front());
        }
        
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return SWAndDequeMethod(nums , k);
    }
};