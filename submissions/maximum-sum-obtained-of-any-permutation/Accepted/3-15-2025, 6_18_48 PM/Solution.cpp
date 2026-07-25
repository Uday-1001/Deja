// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

class Solution {
public:
    int MOD = 1000000007;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        sort(nums.begin() ,nums.end());
        //priority queue creation
        priority_queue<pair<int,int>>pq;
        
        // diff array creation
        vector<long long>diff_array(nums.size(),0LL);

        for(vector<int>req : requests)
        {
            int start = req[0];
            int end = req[1];

            diff_array[start] += 1;
            if(end+1 < diff_array.size())
            {
                diff_array[end+1] -= 1;
            }
        }
        //cumulative sum
        for(int i = 1 ; i<diff_array.size() ;i++)
        {
            diff_array[i] += diff_array[i-1];
        }
        //pushing pair in priority queue
        for(int i =0 ; i<diff_array.size() ; i++)
        {
            pq.push({diff_array[i] , i});
        }
        // here we get the desired permutation
        int index = nums.size()-1;
        while(!pq.empty())
        {
            pair<long,long>p;
            p = pq.top();
            diff_array[p.second] = nums[index];
            index--;
            pq.pop();
        }

        vector<long long>presum(diff_array.size());
        presum[0] = diff_array[0];
        for(int i = 1 ; i<diff_array.size() ; i++)
        {
            presum[i] = diff_array[i] + presum[i-1];
        }

        long long sum =0;
        for(auto &req : requests)
        {
            int start = req[0]; 
            int end = req[1];
            
            if(start == 0){
                sum += presum[end];
            }
            else{
                sum += presum[end]- presum[start-1];
            }
        }
        return sum % MOD;    
    }
};