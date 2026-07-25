// https://leetcode.com/problems/count-square-sum-triples

class Solution {
public:
    int countTriples(int n) {
        vector<bool>allsquares(n*n+1 , false);
        for(int i =1 ; i<=n ; i++)
        {
            allsquares[i*i] = true;
        }

        int count = 0;
        for(int i =1 ; i<=n ; i++)
        {
            for(int j = i+1 ; j <= n ; j++)
            {
                int sum = (i*i) + (j*j);
                if(sum <= n*n and allsquares[sum]) count++;
            }
        }
        return count*2;
    }
};