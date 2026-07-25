// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;

        priority_queue<int>maxheap;
        priority_queue<int , vector<int> , greater<int>>minheap;

        vector<int>min_n_elem(m);
        min_n_elem[0] = -1;

        vector<int>max_n_elem(m);
        max_n_elem[m-1] = -1;

        int sum = 0;
        for(int i=0 ; i<m ; i++)
        {
            maxheap.push(nums[i]);

            sum += nums[i];

            if(maxheap.size() > n)
            {
                sum -= maxheap.top();
                maxheap.pop();
            }

            if(maxheap.size() == n) min_n_elem[i] = sum;
        }

        sum = 0;
        for(int i=m-1 ; i>=0 ; i--)
        {
            minheap.push(nums[i]);

            sum += nums[i];

            if(minheap.size() > n)
            {
                sum -= minheap.top();
                minheap.pop();
            }

            if(minheap.size() == n) max_n_elem[i] = sum;
        }
        
        int min_diff = INT_MAX;
        for(int i=0 ; i<m-1 ; i++)
        {
            if(min_n_elem[i] != -1 && max_n_elem[i+1] != -1)
            {
                min_diff = min(min_diff , (min_n_elem[i] - max_n_elem[i+1]));
            }
        }

        return min_diff;
    }
};