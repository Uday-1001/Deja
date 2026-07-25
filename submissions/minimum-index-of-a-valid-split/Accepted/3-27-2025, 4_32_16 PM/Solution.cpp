// https://leetcode.com/problems/minimum-index-of-a-valid-split

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>left;
        unordered_map<int,int>right;

        for(auto &x : nums)
        {
            right[x]++;
        }

        for(int i = 0 ; i<nums.size() ; i++)
        {
            left[nums[i]]++;
            right[nums[i]]--;

            int n1 = i+1;
            int n2 = n-i-1;

            if(left[nums[i]] > n1/2 && right[nums[i]] > n2/2)
            {
                return i;
            }
        }
    return -1;
    }
};