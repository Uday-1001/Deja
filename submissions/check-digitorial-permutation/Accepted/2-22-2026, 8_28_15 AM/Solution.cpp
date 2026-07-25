// https://leetcode.com/problems/check-digitorial-permutation

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int>fact(10 , 1);
        for(int i = 1 ; i<=9 ; i++){
            fact[i] = fact[i-1] * i;
        }

        vector<int>digits(10 , 0);
        int temp = n;
        while(temp > 0){
            int digit = temp % 10;
            digits[digit]++;
            temp /= 10;
        }

        int sum = 0;
        for(int i = 0 ; i<=9 ; i++){
            sum += (digits[i] * fact[i]);
        }

        vector<int>countdigitsofsum(10 , 0);
        temp = sum;
        while(temp > 0){
            int digit = temp % 10;
            countdigitsofsum[digit]++;
            temp /= 10;
        }

        if(countdigitsofsum != digits) return false;

        int len1 = 0 , len2 = 0;
        temp = n;
        while(temp > 0){
            len1++;
            temp /= 10;
        }
        temp = sum;
        while(temp > 0){
            len2++;
            temp /= 10;
        }

        if(len2 < len1) return false;
        return true;
    }
};