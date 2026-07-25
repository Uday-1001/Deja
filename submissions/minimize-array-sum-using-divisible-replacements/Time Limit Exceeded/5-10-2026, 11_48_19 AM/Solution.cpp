// https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements

class Solution {
public:
    using ll = long long;
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        sort(rbegin(nums) , rend(nums));

        vector<int>divisor(n , -1);
        for(int i = 0 ; i+1<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                if(nums[i] % nums[j] == 0) divisor[i] = nums[j];
            }
        }

        ll total = accumulate(begin(nums) , end(nums) , 0LL);
        for(int i = 0 ; i<divisor.size() ; i++)
        {
            if(divisor[i] == -1) continue;
            else 
            {
                total -= nums[i];
                total += divisor[i];
            }
        }
        return total;
    }
};