// https://leetcode.com/problems/make-array-elements-equal-to-zero

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int>prefix(n+1);
        vector<int>suffix(n+1);

        for(int i=0 ; i<n ; i++)
        {
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            suffix[i] = suffix[i+1] + nums[i];
        }

        for(int i=1 ; i<n-1 ; i++)
        {
            if(nums[i] == 0 and prefix[i] == suffix[i+1]) ans++;
        }        
        return ans*2;
    }
};