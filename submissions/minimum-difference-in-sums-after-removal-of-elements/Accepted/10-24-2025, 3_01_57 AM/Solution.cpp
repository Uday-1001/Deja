// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        long long n = m / 3;

        priority_queue<long long>maxheap;
        priority_queue<long long , vector<long long> , greater<long long>>minheap;

        vector<long long>min_n_elem(m);
        min_n_elem[0] = -1;

        vector<long long>max_n_elem(m);
        max_n_elem[m-1] = -1;

        long long sum = 0;
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
        
        long long min_diff = LLONG_MAX;
        for(int i=n-1 ; i<m-n ; i++)
        {
            min_diff = min(min_diff , (long long)(min_n_elem[i] - max_n_elem[i+1]));
        }

        return min_diff;
    }
};