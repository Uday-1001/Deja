// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        deque<int>q;
        
        //computing the first window and storing the answer for it
        for(int i =0 ; i<k ; i++)
        {
            while(!q.empty() && (nums[q.back()] <= nums[i]))
            {
                q.pop_back();
            }
                q.push_back(i);
        }
        //storing the answer for the first window that has been made
        ans.push_back(nums[q.front()]);

        //now computing the other remaining windows
        for(int i=k ; i<nums.size() ; i++)
        {
            //removal of the out of range elements
            if(!q.empty() && (i - q.front() >= k))
            {
                q.pop_front();
            }
            //addition of the in range elements
            while(!q.empty() && (nums[q.back()] <= nums[i]))
            {
                q.pop_back();
            }
            q.push_back(i);

            //store the ans
            ans.push_back(nums[q.front()]);
        }
    return ans;
    }
};