// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); i++)
        {
            int count = 0;
            for(int j=0; j<nums.size() ; j++)
            {
                if(j != i and nums[j] < nums[i]) count++;
            }
            ans.push_back(count);
        }
    return ans;
    }
};