// https://leetcode.com/problems/construct-uniform-parity-array-ii

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int mini = *min_element(begin(nums1) , end(nums1));
        if(mini % 2 != 0) return true;

        for(auto it : nums1) if(it % 2 != 0) return false;
        return true;
    }
};