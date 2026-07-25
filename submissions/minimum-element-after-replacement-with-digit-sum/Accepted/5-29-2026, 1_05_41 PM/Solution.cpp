// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum

class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto it : nums)
        {
            int sum = 0;
            while(it > 0) 
            {
                sum += (it % 10);
                it /= 10;
            }
            mini = min(mini , sum);
        }
        return mini;
    }
};