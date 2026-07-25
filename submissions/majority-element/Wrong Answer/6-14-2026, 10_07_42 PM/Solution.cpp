// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(count == 0)
            {
                count = 1;
                elem = nums[i];
            }

            if(elem == nums[i]) count++;
            else count--;
        }
        
        return elem;
    }
};