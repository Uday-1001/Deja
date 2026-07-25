// https://leetcode.com/problems/zero-array-transformation-ii

class Solution {
public:
    bool ispossible(vector<int>&nums , vector<vector<int>>& queries , int mid)
    {
        vector<int>diff_array(nums.size(),0);
        for(int i =0 ; i<=mid ; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int value = queries[i][2];
            //difference array ka creation
            diff_array[start] += value;
            if(end + 1 < diff_array.size())
            {
                diff_array[end + 1] -= value;
            }
        }
            // cumulative sum
            for(int i = 1 ; i<diff_array.size() ; i++)
            {
                diff_array[i] = diff_array[i] + diff_array[i-1];
            }

            for(int i = 0 ; i<nums.size() ; i++)
            {
                diff_array[i] = nums[i] - diff_array[i];
                if(diff_array[i] > 0)
                return false;
            }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0 , e = queries.size()-1;
        int ans = -1;

        int count = 0; 
        for(int i = 0 ; i<nums.size(); i++)
        {
            if(nums[i] == 0) count++;
        }
        if(count == nums.size()) return 0;

        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(ispossible(nums , queries , mid))
            {
                ans = mid + 1;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;  
    }
};