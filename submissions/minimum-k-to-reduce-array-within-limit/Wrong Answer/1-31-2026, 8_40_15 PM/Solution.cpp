// https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit

class Solution {
public:
    using ll = long long;
    long long binarysearch(vector<int>&nums , int mid)
    {
        ll opr = 0;
        for(int it : nums) opr += (it + mid - 1) / mid;
        return opr;
    }
    
    int minimumK(vector<int>& nums) {
        int s = 1;
        int e = *max_element(nums.begin() , nums.end());
        long long ans = e;

        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(binarysearch(nums , mid) <= (ll)(mid * mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        
    return ans;
    }
};