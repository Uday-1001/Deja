// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positives;
        vector<int>negatives;

        vector<int>ans;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i] > 0)
            {
                positives.push_back(nums[i]);
            }
            else
                negatives.push_back(nums[i]);
        }
        
        int p1 = 0;
        int p2 = 0;

        while(p1<positives.size() && p2 < negatives.size())
        {
            ans.push_back(positives[p1]);
            ans.push_back(negatives[p2]);
            p1++;
            p2++;
        }
        return ans ;
    }
};