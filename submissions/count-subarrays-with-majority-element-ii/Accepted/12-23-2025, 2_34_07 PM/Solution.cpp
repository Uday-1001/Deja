// https://leetcode.com/problems/count-subarrays-with-majority-element-ii

class Solution {
public:
    using ll = long long;
    ll count = 0;

    void merger(vector<int>&arr , int s , int e , int mid)
    {
        ll n1 = mid - s + 1;
        ll n2 = e - mid;
        
        vector<int>left(n1) , right(n2);

        ll idx = s;
        for(ll i =0 ; i<n1 ; i++) left[i] = arr[idx++];
        
        idx = mid + 1;
        for(ll i =0 ; i<n2 ; i++) right[i] = arr[idx++];

        ll i = 0 , j = 0;
        idx = s;
        while(i < n1 and j < n2)
        {
            if(left[i] < right[j])
            {
                count += (n2 - j);
                arr[idx++] = left[i++];
            }
            else arr[idx++] = right[j++];
        }
        while(i < n1) arr[idx++] = left[i++];
        while(j < n2) arr[idx++] = right[j++];
    }

    void mergesort(vector<int>&arr , ll s , ll e)
    {
        if(s >= e) return;

        ll mid = s + (e - s) / 2;
        mergesort(arr , s , mid);
        mergesort(arr , mid + 1 , e);
        merger(arr , s , e , mid);
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll n = nums.size();

        bool present = false;
        for(auto it : nums)
        {
            if(it == target) present = true;
        }
        if(!present) return 0;

        vector<int>modified(n , 0);
        for(ll i = 0; i<n ; i++)
        {
            if(nums[i] == target) modified[i] = 1;
            else modified[i] = -1;
        }

        vector<int>cumsum(n+1 , 0);
        cumsum[0] = 0;
        cumsum[1] = modified[0];
        for(ll i = 2 ; i <= n ; i++)
        {
            cumsum[i] = cumsum[i-1] + modified[i-1];
        }

        mergesort(cumsum , 0 , n);
        return count;
    }
};