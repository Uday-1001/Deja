// https://leetcode.com/problems/rotate-non-negative-elements

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>positives;
        for(auto it : nums) if(it > 0) positives.push_back(it);

        if(positives.empty()) return nums;
        int rightshift = k % positives.size();
        int leftshift = (positives.size() - rightshift) % positives.size();
        
        reverse(positives.begin(), positives.end());
        reverse(positives.begin(), positives.begin() + leftshift);
        reverse(positives.begin() + leftshift, positives.end());

        vector<int>ans(n);
        for(int i =0 ; i< n ; i++){
            if(nums[i] > 0) ans[i] = INT_MIN;
            else ans[i] = nums[i];
        }

        int idx = 0;
        for(int i =0 ; i< n ; i++){
            if(ans[i] == INT_MIN)
            {
                ans[i] = positives[idx++];
            }
        }
    return ans;
        
    }
};