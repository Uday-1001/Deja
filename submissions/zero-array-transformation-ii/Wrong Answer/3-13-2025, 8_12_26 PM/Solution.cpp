// https://leetcode.com/problems/zero-array-transformation-ii

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int used = -1;
        for(int i = 0 ; i<queries.size() ; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int value = queries[i][2];

            for(int j= start ; j<=end ; j++)
            {
                nums[j] -= value;
            }

            for(int k= 0 ; k<nums.size(); k++)
            {
                if(nums[k] != 0)
                break;
                else
                used = i;
            }
        }
        return used;
    }
};