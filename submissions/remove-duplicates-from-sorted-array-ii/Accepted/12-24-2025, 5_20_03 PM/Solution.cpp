// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int end = start + 1;
        int index = 1;

        int same_cnt = 1;
        while(end < nums.size())
        {
            if(nums[start] == nums[end])
            {
                if(same_cnt >= 2) end++;
                else
                {
                    same_cnt++;
                    nums[index++] = nums[end++];
                }
            }
            else
            {
                same_cnt = 1;
                start = end;
                nums[index++] = nums[end++];
            }
        }
    return index;
    }
};