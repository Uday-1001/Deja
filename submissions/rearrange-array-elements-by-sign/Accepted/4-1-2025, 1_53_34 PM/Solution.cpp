// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
    vector<int> result(n);

    int pos = 0, neg = 1; // Position for next positive and negative numbers

    for (int num : nums) {
        if (num > 0) { 
            result[pos] = num; 
            pos += 2;
        } else { 
            result[neg] = num; 
            neg += 2;
        }
    }

    nums = result; // Copy back to original array
   return nums;
    }
};