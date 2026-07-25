// https://leetcode.com/problems/count-indices-with-opposite-parity

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>ans(nums.size());
        int odd = 0 , even = 0;

        for(auto it : nums) if(it & 1) odd++;
        else even++;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] & 1){
                odd--;
                ans[i] = even;
            }
            else {
                even--;
                ans[i] = odd;
            }
        }
        return ans;
    }
};