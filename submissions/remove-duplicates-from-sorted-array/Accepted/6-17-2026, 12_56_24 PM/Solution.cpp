// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index{};
        int elem;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(elem != nums[i])
            {
                nums[index++] = nums[i];
                elem = nums[i];
            }
        }
        return index;
    }
};