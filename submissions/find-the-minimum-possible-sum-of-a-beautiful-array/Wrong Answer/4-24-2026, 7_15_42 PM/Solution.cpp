// https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array

class Solution {
public:
    const int mod = 1e9 + 7;
    int minimumPossibleSum(int n, int target) {
        int sum = 0;
        int size = 0;

        if(n == 1 and target == 1) return 1;

        for(int i = 1 ; i<=1e9 ; i++)
        {
            if(sum + i == target) continue;
            sum += i;
            size++;
            if(size == n) break;
        }
        return sum % mod;
    }
};