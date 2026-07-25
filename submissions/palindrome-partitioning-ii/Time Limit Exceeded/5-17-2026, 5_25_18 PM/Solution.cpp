// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:

    bool isPalindrome(string& s){
        int i = 0, j = s.length()-1;
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    int solve(string s, int i){
        // base case
        if(i >= s.length()){
            return 0;
        }
        // processing
        int mini = INT_MAX;
        string sub = "";
        for(int j = i; j<s.length(); j++){
            sub.push_back(s[j]);
            if(isPalindrome(sub)){
                int temp = 1 + solve(s, j+1);
                mini = min(mini, temp);
            }
        }
        return mini;
    }

    int minCut(string s) {
        int ans = solve(s, 0);
        return ans - 1;
    }
};