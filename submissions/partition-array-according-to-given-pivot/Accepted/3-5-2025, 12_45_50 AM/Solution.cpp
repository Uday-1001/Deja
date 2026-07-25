// https://leetcode.com/problems/partition-array-according-to-given-pivot

class Solution {
public:
     vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size());
        int left = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                result[left] = nums[i];
                left++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == pivot){
                result[left++] = nums[i];
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > pivot){
                result[left++] = nums[i];
            }
        }
        return result;
    }
};