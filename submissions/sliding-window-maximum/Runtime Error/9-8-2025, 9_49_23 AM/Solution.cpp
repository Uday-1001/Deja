// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        queue<int>q;

        if(nums.size() == 1)
        {
            ans.push_back(nums[0]);
            return ans;
        }

        //computing the first window and storing the answer for it
        for(int i=1 ; i<k ; i++)
        {
            int maxi = nums[0];
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                q.push(i);
            }  
        }
        //storing the answer for the first window that has been made
        if(q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(nums[q.back()]);
        }

        //now computing the other remaining windows
        for(int i=k ; i<nums.size() ; i++)
        {
            //removal of the out of range elements
            if(!q.empty() && (i - q.front() >= k))
            {
                q.pop();
            }
            //addition of the in range elements
            int maxi = q.back();
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                q.push(i);
            }
            //store the ans
            if(q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(nums[q.back()]);
            }
        }
    return ans;
    }
};