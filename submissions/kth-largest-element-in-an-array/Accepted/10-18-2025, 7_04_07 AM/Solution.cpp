// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using Min Heap
        priority_queue<int , vector<int> , greater<int>>pq;

        for(int i=0 ; i<k ; i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k ; i<nums.size() ; i++)
        {
            if(nums[i] > pq.top())
            {
                pq.push(nums[i]);
                pq.pop();
            }
        }

        return pq.top();
    }
};