// https://leetcode.com/problems/longest-balanced-subarray-i

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int l = 0 ; l<n ; l++)
        {
            unordered_set<int>evens , odds;

            for(int r = l ; r<n ;r++)
            {
                if(nums[r] & 1) odds.insert(nums[r]);
                else evens.insert(nums[r]);
                
                //checking the size of each set if same 
                if(odds.size() == evens.size()) ans = max(ans , r-l+1);
            }
        }
        return ans;
    }
};