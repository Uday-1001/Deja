// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count =0;
        for(auto num : nums)
        {
            string s = to_string(num);
            int len = s.size();
            if(len % 2 == 0)
            {
                count ++;
            }
        }
        return count;
    }
};