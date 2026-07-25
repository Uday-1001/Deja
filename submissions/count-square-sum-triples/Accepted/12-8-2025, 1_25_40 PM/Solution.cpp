// https://leetcode.com/problems/count-square-sum-triples

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i = 1 ; i<= n ; i++)
        {
            for(int j =i+1 ; j <=n ; j++)
            {
                for(int k = j+1 ; k <=n ; k++)
                {
                    int a = i;
                    int b = j;
                    int c = k;
                    int square_sum = (a*a) + (b*b);
                    if(sqrt(square_sum) == c) count++;
                }
            }
        }
        return count*2;
    }
};