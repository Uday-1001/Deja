// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = -1;
        int mini = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            for(int j = i+1 ; j<nums.size() ; j++)
            {
                for(int k = j+1 ; k < nums.size() ; k++)
                {
                    if(nums[i] == nums[j] and nums[j] == nums[k])
                    {
                        ans = abs(i-j) + abs(j-k) + abs(k-i);
                        mini = min(mini , ans);
                    }
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};