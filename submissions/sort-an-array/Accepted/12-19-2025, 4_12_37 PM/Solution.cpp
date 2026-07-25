// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    void merger(vector<int>&nums , int start , int end , int mid){
        int len1 = mid-start+1;
        int len2 = end - mid;

        vector<int>left(len1) , right(len2);

        int index = start;
        for(int i = 0 ; i < len1 ; i++) left[i] = nums[index++];

        index = mid+1;
        for(int i = 0 ; i < len2 ; i++) right[i] = nums[index++];

        int i = 0;
        int j = 0;
        index = start;
        while(i < len1 && j < len2)
        {
            if(left[i] <= right[j])
            {
                nums[index++] = left[i++];
            }
            else
            {
                nums[index++] = right[j++];
            }
        }
        while(i < len1)
        {
            nums[index++] = left[i++];
        }
        while(j < len2)
        {
            nums[index++] = right[j++];
        }
    }
    void mergesort(vector<int>&nums , int start , int end){
        if(start < end)
        {
            int mid = start + (end - start) /2;
            mergesort(nums , start , mid);
            mergesort(nums , mid+1 , end);

            merger(nums , start , end , mid);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums , 0 , nums.size()-1);
        return nums;
    }
};