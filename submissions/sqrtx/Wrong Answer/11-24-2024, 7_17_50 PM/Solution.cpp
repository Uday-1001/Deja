// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int mid = s+(e-s)/2;
        int ans=-1;
        long long int product = mid *mid;
        while(s<=e){
            if(product==x){
                return mid;
            }
            if(mid*mid<x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid= s+(e-s)/2;
        }
        return ans;
    }
};