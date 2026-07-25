// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    void quicksort(vector<int>&nums , int start , int end)
    {
        //base case 
        if(start >= end) return;
        
        int pivot = end;
        int i = start - 1;
        int j = start;

        while(j < pivot)
        {
           if(nums[j] < nums[pivot])
            {
                ++i;
                swap(nums[j] , nums[i]);
            }
            j++; 
        }
        //when you exit the while loop , you have the largest element in the end and it was its correct place
        i++;
        swap(nums[i] , nums[pivot]);

        //calling to sort the left part
        quicksort(nums , start , i-1);
        //calling to sort the right part
        quicksort(nums , i+1 , end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        quicksort(nums , start , end);
        return nums;
    }
};