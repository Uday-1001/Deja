// https://leetcode.com/problems/count-elements-with-at-least-k-greater-values

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return n;

        vector<int>copy = nums;
        sort(copy.rbegin() , copy.rend());

        int elem = copy[k-1];
        int ans = 0;
        for(auto n : nums){
            if(n < elem) ans++;
        }
    return ans;
    }
};