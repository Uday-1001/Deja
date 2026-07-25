// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public: 
    int solve(int n)
    {
        if(n == 1 or n == 0) return 1;

        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            ans += solve(i - 1) * solve(n - i);
        }
        return ans;
    }
    int numTrees(int n) {
        return solve(n);
    }
};