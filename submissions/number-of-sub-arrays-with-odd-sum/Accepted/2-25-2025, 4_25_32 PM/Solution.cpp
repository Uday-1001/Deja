// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int pre_sum = 0;
        int even_cnt = 1;
        int odd_cnt = 0;
        int result = 0;

        for(auto num : arr)
        {
            pre_sum += num;
            if(pre_sum % 2 == 0)
            {
                result = (result + odd_cnt) % 1000000007;
                even_cnt++;
            }
            else
            {
                result = (result + even_cnt) % 1000000007;
                odd_cnt++;
            }
        }
        return result ;
    }
};