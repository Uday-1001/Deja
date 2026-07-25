// https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array

class Solution {
public:
    const int mod = 1e9 + 7;

    long long merge(vector<int>&positions , int low , int mid , int high)
    {
        vector<int>temp;

        int left = low;
        int right = mid + 1;

        long long inversions = 0;

        while(left <= mid and right <= high)
        {
            if(positions[left] <= positions[right])
            {
                temp.push_back(positions[left]);
                left++;
            }
            else
            {
                inversions += (mid - left + 1);
                temp.push_back(positions[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(positions[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(positions[right]);
            right++;
        }

        for(int i = low ; i <= high ; i++) positions[i] = temp[i - low];

        return inversions;
    }

    long long mergeSort(vector<int>&positions , int low , int high)
    {
        if(low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long inversions = 0;

        inversions += mergeSort(positions , low , mid);
        inversions += mergeSort(positions , mid + 1 , high);
        inversions += merge(positions , low , mid , high);

        return inversions;
    }

    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int>positions(n , -1);

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] < a) positions[i] = 0;
            else if(nums[i] >= a and nums[i] <= b) positions[i] = 1;
            else positions[i] = 2;
        }

        return mergeSort(positions , 0 , n - 1) % mod;
    }
};