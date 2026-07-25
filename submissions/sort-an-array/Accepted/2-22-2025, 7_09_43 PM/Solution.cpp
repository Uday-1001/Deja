// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    void merger(vector<int>&nums , int start , int end , int mid){
        vector<int>temp;
        int i = start;
        int j = mid + 1;
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= end)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for(int index = 0 ; index < temp.size() ; index++)
        {
            nums[start + index] = temp[index];       
        }
    }
    void mergesort(vector<int>&nums , int start , int end){
        if(start  < end)
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