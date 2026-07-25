// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int binarysearch(vector<int>& nums, int s , int target){
        int e= nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s=mid+1;
            }
            else{
                e =mid-1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set <pair<int,int>> ans;
        for(int i=0 ; i<nums.size(); i++){
            if(binarysearch(nums,i+1,nums[i]+k) != -1){

                ans.insert({nums[i],nums[i]+k});
            }
        }
      return ans.size();
    }
};