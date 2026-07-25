// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int byrec(vector<int>&nums , int i , int sum)
    {
        //base case 
        if(i >= nums.size())
        {
            if(sum % 3 == 0) return sum;
            return INT_MIN;
        }

        //ek case hum solve karenge 
        int include = byrec(nums , i+1 , sum + nums[i]);
        int exclude = byrec(nums , i+1 , sum);

        return max(include , exclude);
    }

    int maxSumDivThree(vector<int>& nums) {
        return byrec(nums , 0 , 0);
    }
};