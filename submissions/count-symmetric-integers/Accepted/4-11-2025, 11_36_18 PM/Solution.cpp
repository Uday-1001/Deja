// https://leetcode.com/problems/count-symmetric-integers

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        
        for(int i = low ; i<= high ; i++)
        {
            string st = to_string(i);
            int len = st.size();

            if(len & 1) continue;

            int left_sum = 0;
            int right_sum = 0;

            for(int i = 0 ; i <len/2 ; i++)
            {
                left_sum += (char)st[i];
            }

            for(int i = len/2 ; i<len ; i++)
            {
                right_sum += (char)st[i];
            }

            if(left_sum == right_sum) ans++;
        }
        return ans;
    }
};