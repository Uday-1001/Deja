// https://leetcode.com/problems/trionic-array-ii

class Solution {
public:
    using ll = long long;
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        ll maxsum = LLONG_MIN;

        vector<ll>cum(n);
        cum[0] = nums[0];
        //here is the cummulative sum vector
        for(int i = 1 ; i<n ; i++) cum[i] = cum[i-1] + nums[i];
        
        for(int i = 0 ; i<n ; i++)
        {
            int j = i;
            while(j+1 < n and nums[j] < nums[j+1]) j++;
            int pointP = j;
            if(pointP == i) continue;
            
            while(j+1 < n and nums[j] > nums[j+1]) j++;
            int pointQ = j;
            if(pointQ == pointP) continue;

            while(j+1 < n and nums[j] < nums[j+1]) j++;
            int pointR = j;
            if(pointR == pointQ) continue;

            //if we get all points then we have to find the sum of the array

            ll sum = cum[pointR] - (i > 0 ? cum[i-1] : 0);
            maxsum = max<ll>(maxsum , sum);
        }
        return maxsum;
    }
};