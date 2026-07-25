// https://leetcode.com/problems/minimum-index-of-a-valid-split

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int majority = -1;
        int count = 0;
        //getting the maximum element that is present in the array
        for(int i = 0 ;i<nums.size() ;i++)
        {
            if(count == 0)
            {
                majority = nums[i];
                count = 1;
            }
            else if(majority == nums[i])
            {
                count++;
            }
            else
                count--;
        }
     //getting the count of the maximum present element of the array
        int maj_count = 0;
        for(int  i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i] == majority)
            {
                maj_count++;
            }
        }

        int prefix_count = 0;
        for(int i =0 ; i<n-1 ; i++)
        {
            if(nums[i] == majority)
            {
                prefix_count++;
                maj_count--;
            }
        
            int left_size = i+1;
            int right_size = n-i-1;

            if(prefix_count > left_size/2 && maj_count > right_size/2)
            {
                return i;
            }
        }
    return -1;
    }
};