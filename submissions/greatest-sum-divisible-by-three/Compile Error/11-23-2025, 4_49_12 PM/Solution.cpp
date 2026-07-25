// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums) , end(nums) , 0);
        int ans = 0;
        vector<int>remain1;
        vector<int>remain2;

        for(auto num : nums)
        {
            if(num % 3 == 1) remain1.push_back(num);
            else
            remain2.push_back(num);
        }
        

        sort(begin(remain1) , end(remain1));
        sort(begin(remain2) , end(remain2));

        else if(sum % 3 == 1)
        {
            int to_remove1 = remain1.size() > 0 ? remain1[0] : 1e8;
            int to_remove2 = remain2.size() > 1 ? remain2[0] + remain2[1] : 1e8;

            int deduction_req = min(to_remove1 , to_remove2);
            if(deduction_req == 1e8) return 0;

            ans = sum - deduction_req;
        }
        else
        {
            int to_remove1 = remain1.size() > 1 ? remain1[0] + remain1[1]: 1e8;
            int to_remove2 = remain2.size() > 0 ? remain2[0] : 1e8;

            int deduction_req = min(to_remove1 , to_remove2);
            if(deduction_req == 1e8) return 0;

            ans = sum - deduction_req;
        }
    return ans;
    }
};