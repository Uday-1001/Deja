// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums) , end(nums));
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=1 ; i<n-2 ; i++)
        {
            int left = i+1;
            int right = n-1;

            while(left < right)
            {
                int sum = nums[left] + nums[i] + nums[right];

                if(abs(target-sum) < abs(target-ans))
                {
                    ans = sum;
                }

                if(sum > target) 
                    right--;
                else if(sum < target) 
                    left++;
                else if(sum == target) 
                    return sum;
            }
        }
    return ans;
    }
};