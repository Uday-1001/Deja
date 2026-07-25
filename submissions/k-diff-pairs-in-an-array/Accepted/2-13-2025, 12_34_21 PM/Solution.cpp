// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int binarySearch(vector<int>& nums,int s , int x)
    {
        int e = nums.size()-1;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == x)
            {
                return mid ;
            }
            if(nums[mid] > x)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
    return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin() ,nums.end());
        set<pair<int,int>>ans;

        for(int i = 0; i<nums.size() ;i++)
        {
            int final_ans = binarySearch(nums,i+1,nums[i]+k);

            if(final_ans != -1)
            {
                ans.insert({nums[i],nums[i]+k});
            }
        }
    return ans .size();
    }
};