// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr) , end(arr));
        arr[0] = 1;
        for(int i = 1 ; i<arr.size() ; i++) arr[i] = min(arr[i] , arr[i-1]+1);
    
        return *max_element(begin(arr) , end(arr));
    }
};