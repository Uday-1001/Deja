// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool ispossible(vector<int>& nums, int k , int mid)
    {
        int count = 1;
        int sum = 0 ;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(sum + nums[i] >= mid)
            {
                count++;
                sum = nums[i];
                if(count > k) return false;
            }
            else
            {
                sum += nums[i];
            }
        }
        return true;
        
    }

    int splitArray(vector<int>& nums, int k) {
        int s = *min_element(nums.begin() , nums.end());
        int e = accumulate(nums.begin() , nums.end() , 0);
        int ans = -1;

        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(ispossible(nums , k , mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
    return ans - 1 ;
    }
};