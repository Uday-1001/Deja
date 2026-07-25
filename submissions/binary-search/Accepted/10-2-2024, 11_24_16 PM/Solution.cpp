// https://leetcode.com/problems/binary-search

class Solution {
public:
   
        int search(vector<int>& nums, int target) {
        int size=nums.size();
        int f=0;
        int l=size-1;
        int ans=-1;
        while(f<=l)
        { 
            int mid=(f+l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return ans;
            }
            else if(nums[mid]<target)
            {
                f=mid+1;
            }
            else{
                l=mid-1;
            }
            

        }return ans ;
        
    } 
};