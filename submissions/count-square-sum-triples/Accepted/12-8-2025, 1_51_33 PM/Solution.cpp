// https://leetcode.com/problems/count-square-sum-triples

class Solution {
public:
    int resultofBS(int s , int e , int square_sum)
    {
        while(s <= e)
        {
            int mid = s + (e-s) / 2;
            if(square_sum == mid * mid) return mid;
            else if(square_sum > mid * mid) s = mid +1;
            else e = mid -1;
        }
    return -1;
    }

    int countTriples(int n) {
        int count = 0;
        for(int i = 3 ; i <= n ; i++)
        {
            for(int j =i+1 ; j <= n ; j++)
            {
                int square_sum = (i*i) + (j*j);
                if(sqrt(square_sum) == resultofBS(1, n , square_sum)) count++;
            }
        }
        return count*2;
    }
};