// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        
        //calculating the pq for the first window and then the next windows follow
        for(int i=0; i<k ; i++)
        {
            pq.push({nums[i] , i});
        }
        //insert the answer of the first window into ans vector
        ans.push_back(pq.top().first);

        //calculate for the index  of the top element to be inside the valid window range 
        //If not , then -> utha ke phek saale ko bahar aur aiso ko aur dhoondh ke pelo queue me
        for(int i=k ; i<nums.size() ; i++)
        {
            pq.push({nums[i] , i});
            while(pq.top().second <= i-k)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};