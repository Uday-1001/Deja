// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings

class Solution {
public:
    unordered_set<string>st;

    bool checkPalindrome(string &s , int k)
    {
        if(s.size() < k) return false;
        int i = 0;
        int j = s.size()-1;

        while(i <= j){
            if(s[i] != s[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
    return true;
    }
    
    int fxn(string &s , int k)
    {
        int n = s.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j<n ; j++){
                if(j-i+1 < k) continue;
                else 
                {
                    string str = s.substr(i , j);
                    st.insert(str);
                }
            }
        }
        int ans = 0;
        for(auto it : st){
            if(checkPalindrome(it , k)) ans++;
        }
    return ans;

        
    }

    
    int maxPalindromes(string s, int k) {
        return fxn(s , k);
    }
};