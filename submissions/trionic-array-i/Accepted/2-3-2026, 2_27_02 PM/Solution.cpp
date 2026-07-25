// https://leetcode.com/problems/trionic-array-i

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int end = n-1;
        
        while(i+1 < n and nums[i] < nums[i+1]) i++;

        if(i == 0 or i == end) return false;
        //got point P here
        int pointP = i;

        while(i+1 < n and nums[i] > nums[i+1]) i++;

        if(i == pointP or i == end) return false;
        //got point Q here
        int pointQ = i;

        while(i+1 < n and nums[i] < nums[i+1]) i++;

        return i != pointQ and i == end;
    }
};