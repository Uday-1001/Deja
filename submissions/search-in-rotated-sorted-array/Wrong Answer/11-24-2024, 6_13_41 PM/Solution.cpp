// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
        int getpivot(vector<int>arr){
            int s=0;
            int n=arr.size();
            int e=n-1;
            int mid= s+(e-s)/2;
            while(s<=e){
                if(s==e){
                    return s;
                }
                if(mid+1<n && arr[mid]>arr[mid+1]){
                    return mid;
                }
                if(arr[s]>arr[mid])
                {
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
                mid= s+(e-s)/2;    
                }
                return -1;
        }  
        int Binary(int s,int e,int target, vector<int>arr){
            int mid=s+(e-s)/2;
            while(s<=e){
                if(arr[mid]==target)
                {
                    return mid;
                }
                if(target>arr[mid])
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
                mid= s+(e-s)/2;
            } 
            return -1;
        }   
            int search(vector<int>& nums, int target) {
                int pivot= getpivot(nums);
                int n=nums.size();
                if(target>=0 && target<=nums[pivot]){
                    int ans= Binary(0,pivot,target,nums);
                    return ans;
                }
                else{
                    int ans= Binary(pivot+1,n-1,target,nums);
                    return ans;
                }
                return -1;
    }

};