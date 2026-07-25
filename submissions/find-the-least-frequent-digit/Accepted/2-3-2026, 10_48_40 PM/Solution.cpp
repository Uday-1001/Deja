// https://leetcode.com/problems/find-the-least-frequent-digit

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int , int>mp;
        while(n > 0)
        {
            mp[n % 10]++;
            n /= 10;
        }

        int ans = 0;
        int mini = INT_MAX;

        for(auto it : mp)
        {
            if(it.second < mini)
            {
                mini = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};