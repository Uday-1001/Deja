// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    vector<int>ans;
    void merger(vector<pair<int,int>>&arr , int start , int end , int mid)
    {
        int l1 = mid - start + 1;
        int l2 = end - mid;

        vector<pair<int,int>>left(l1 , {0 , 0}) , right(l2 , {0 , 0}); 

        int index = start;
        for(int i = 0; i<l1 ; i++) left[i] = arr[index++];
        index = mid + 1;
        for(int i = 0; i<l2 ; i++) right[i] = arr[index++];

        int i = 0 , j = 0;
        int count = 0;
        int mainindex = start;
        while(i < l1 and j < l2)
        {
            if(left[i].first <= right[j].first)
            {
                ans[left[i].second] += count;
                arr[mainindex++] = left[i++];
            }
            else 
            {
                count++;
                arr[mainindex++] = right[j++];
            }
        }
        while(i < l1)
        {
            ans[left[i].second] += count;
            arr[mainindex++] = left[i++];
        } 
        while(j < l2) arr[mainindex++] = right[j++];
    }

    void mergesort(vector<pair<int,int>>&arr , int start , int end)
    {
        if(start >= end) return;

        int mid = start + (end - start) / 2;
        mergesort(arr , start , mid);
        mergesort(arr , mid+1 , end);
        merger(arr , start , end , mid);
    }

    vector<int> countSmaller(vector<int>& nums) {
        ans.resize(nums.size() , 0);
        vector<pair<int,int>>arr;
        for(int i = 0 ; i<nums.size() ; i++) arr.push_back({nums[i] , i});

        mergesort(arr , 0 , nums.size()-1);
        return ans;
    }
};