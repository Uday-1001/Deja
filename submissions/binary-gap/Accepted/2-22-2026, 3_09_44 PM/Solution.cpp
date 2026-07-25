// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int result = 0;

        int curr = 0 , prev = -1;
        while(n > 0)
        {
            int curr_bit = n & 1;
            if(curr_bit == 1)
            {
                if(prev != -1) result = max(result , curr - prev);
                prev = curr;
                curr++;
            }
            else 
            {
                curr++;
            }
            n >>= 1;
        }
    return result;
    }
};