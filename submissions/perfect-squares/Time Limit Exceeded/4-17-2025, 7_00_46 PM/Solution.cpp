// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int recursion(int n)
    {
        //base case
        if(n == 0) return 1;
        if(n < 0) return 0;

        //ek case hum solve karenge baaki recursion sambhalega
        int ans = INT_MAX;

        for(int i = 1 ; i <= sqrt(n) ; i++)
        {
            int square = i * i;
            int count = 1 + recursion(n - square);
            if(count < ans)
            {
                ans = count;
            }
        }
        return ans;
    }
    int numSquares(int n) {
        return recursion(n) - 1; 
    }
};