// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i

class Solution {
public:
    int mod = 1e9 + 7;
    int byrec(int zeros , int ones , bool previsOne , int limit)
    {
        if(zeros == 0 and ones == 0) return 1;

        int ans = 0;
        if(previsOne)
        {
            //if previous was one , then we will explore zero based path
            for(int count = 1 ; count <= min(limit , zeros) ; count++)
            {
                ans += byrec((zeros - count), ones , false , limit);
            }
        }
        else
        {
            //if previous was zero , then we will explore one based path
            for(int count = 1 ; count <= min(limit , ones) ; count++)
            {
                ans += byrec(zeros , (ones - count) , true , limit);
            }
        }

        return ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        int startones = byrec(one , zero , false , limit);
        int startzeros = byrec(one , zero , true , limit);

        return (startones + startzeros) % mod;
    }
};