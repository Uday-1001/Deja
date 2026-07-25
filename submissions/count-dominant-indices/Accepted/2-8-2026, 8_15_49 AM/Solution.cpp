// https://leetcode.com/problems/count-dominant-indices

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i<n-1 ; i++){
            int cnt = n - i - 1;
            long long sum = 0;
            for(int j = i+1 ; j<nums.size() ; j++){
                 sum += nums[j];
            }
            if((long long)nums[i] * cnt > sum) count++;
        }
        return count;
    }
};