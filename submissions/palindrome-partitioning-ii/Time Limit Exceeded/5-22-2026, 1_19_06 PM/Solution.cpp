// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool isPalindrome(string &s , int i , int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int solve(string &s , int i , int j){
        // base case
        if(i >= j) return 0;
        if(isPalindrome(s , i , j)) return 0;

        // the MCM format process
        int mini = INT_MAX;
        for(int k = i ; k<j ; k++)
        {
            int temp = 1 + solve(s , i , k) + solve(s , k+1 , j);
            mini = min(mini , temp);
        }
        return mini;
    }

    int minCut(string s) {
        int ans = solve(s , 0 , s.size()-1 );
        return ans;
    }
};