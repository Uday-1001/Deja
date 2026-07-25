// https://leetcode.com/problems/guess-number-higher-or-lower-ii

class Solution {
public:
    int byrec(int start , int end)
    {
        //base case 
        if(start >= end) return 0;

        //ek case hum solve karenge
        int ans = INT_MAX;
        for(int i=start ; i<end ; i++)
        {
            int lower_path = byrec(start , i-1);
            int higher_path = byrec(i+1 , end);

            ans = min(ans , i + max(lower_path , higher_path));
        }   
    return ans;
    }

    int getMoneyAmount(int n) {
        return byrec(1 , n);
    }
};