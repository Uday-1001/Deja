// https://leetcode.com/problems/trionic-array-i

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=  nums.size();
        vector<int>cum(n);
        cum[0] = 1;

        for(int i = 1 ; i<n ; i++)
        {
            if(nums[i] > nums[i-1]) cum[i] = cum[i-1] + 1;
            else if(nums[i] < nums[i-1]) cum[i] = cum[i-1] - 1;
        }
        set<int>ans;
        for(auto it : cum) ans.insert(it);
        return ans.size() >= 3;
    }
};