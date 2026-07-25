// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=1,e=arr.size()-2;
        while(s<=e) {
            int mid=s+(e-s)/2;

            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){         
                return mid;
            }
            else if(arr[mid-1]<arr[mid]){
                s=mid++;
            }else {
                e=mid--;
            }
        }
        return -1;
    }
};