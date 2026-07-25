// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void recursion(vector<char>&s ,int i)
    {
        int n = s.size();
        if(i >= n/2)
        {
            return;
        }
        swap(s[i] , s[n-i-1]);
        recursion(s , i+1);
    }
    void reverseString(vector<char>& s) {
        recursion(s , 0);
    }
};