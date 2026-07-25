// https://leetcode.com/problems/count-symmetric-integers

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;

        for(int i =low ; i<=high ; i++)
        {
            if(10 <= i && i <= 99 && (i % 11 == 0))
            {
                ans++;
            }
            
            else if(1000 <= i && i <= 9999)
            {
                int first_digit = i / 1000;
                int second_digit = (i / 100) % 10;
                int third_digit = (i / 10) % 10;
                int fourth_digit = i % 10;

                if((first_digit + second_digit) == (third_digit + fourth_digit)) 
                {
                    ans++;
                }
            }
        }
    return ans;
    }
};