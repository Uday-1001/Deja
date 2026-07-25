// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        int mid =s+(e-s)/2;
        while(s<=e){
           
            if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }  
            mid =s+(e-s)/2;
        }
        return mid;
    }
};