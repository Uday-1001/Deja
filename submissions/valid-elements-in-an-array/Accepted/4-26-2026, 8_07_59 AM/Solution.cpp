// https://leetcode.com/problems/valid-elements-in-an-array

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {nums[0]};

        vector<int>leftmax(n) , rightmax(n);
        leftmax[0] = nums[0];
        rightmax[n-1] = nums[n-1];

        for(int i = 1 ; i<n ; i++) leftmax[i] = max(leftmax[i-1] , nums[i]);
        for(int i = n-2 ; i>=0 ; i--) rightmax[i] = max(rightmax[i+1] , nums[i]);

        vector<int>ans;
        for(int i = 0 ; i<n ; i++){
            if(i == 0 or i == n-1) ans.push_back(nums[i]);
            else 
            {
                if(nums[i] > leftmax[i-1] or nums[i] > rightmax[i+1]) ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};