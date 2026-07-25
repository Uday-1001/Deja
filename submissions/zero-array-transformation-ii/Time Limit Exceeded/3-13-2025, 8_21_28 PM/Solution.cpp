// https://leetcode.com/problems/zero-array-transformation-ii

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int temp = 0;
        for(auto x :nums)
        {
            if(x == 0) temp++;
        }
        if(temp == nums.size()) return 0;
        
        for(int i = 0 ; i<queries.size() ; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int value = queries[i][2];

            for(int j= start ; j<=end ; j++)
            {
                nums[j] -= value;
                if(nums[j] < 0) 
                nums[j]=0;
            }
            int count = 0;
            for(int k= 0 ; k<nums.size(); k++)
            {
                if(nums[k] == 0)
                count++;
            }
            if(count == nums.size())
            return i+1;
        }
        return -1;
    }
};