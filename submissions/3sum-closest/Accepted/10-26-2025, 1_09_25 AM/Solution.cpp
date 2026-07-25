// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums) , end(nums));
        int n = nums.size();
        int ans = 1e8;
        
        for(int i=0 ; i<n-2 ; i++)
        {
            int left = i+1;
            int right = n-1;

            while(left < right)
            {
                int sum = nums[left] + nums[i] + nums[right];

                if(abs(target - sum) < abs(ans - target))
                {
                    ans = sum;
                }

                if(sum > target) 
                    right--;
                else if(sum < target) 
                    left++;
                else 
                    return sum;
            }
        }
    return ans;
    }
};