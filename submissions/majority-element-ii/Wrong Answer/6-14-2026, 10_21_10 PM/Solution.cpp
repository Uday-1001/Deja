// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1{} , cnt2{};
        int elem1{INT_MIN} , elem2{INT_MIN};

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(cnt1 == 0 and nums[i] != elem2)
            {
                cnt1 = 1;
                elem1 = nums[i];
            }
            else if(cnt2 == 0 and nums[i] != elem1)
            {
                cnt2 = 1;
                elem2 = nums[i];
            }
            else if(nums[i] == elem1) cnt1++;
            else if(nums[i] == elem2) cnt2++;
            else 
            {
                cnt1--;
                cnt2--;
            }
        }

        int reqcnt1{} , reqcnt2{};
        for(auto it : nums)
        {
            if(it == elem1) reqcnt1++;
            else if(it == elem2) reqcnt2++;
        }

        if(reqcnt1 > (n / 3) and reqcnt2 > (n / 3)) return {elem1 , elem2}; 
        else if(reqcnt1 > (n / 3)) return {elem1};
        else return {elem2};
    }
};