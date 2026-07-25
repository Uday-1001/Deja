// https://leetcode.com/problems/maximize-happiness-of-selected-children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long n = happiness.size();
        sort(happiness.rbegin() , happiness.rend());

        long long ans = 0;
        ans += happiness[0];

        for(int i = 1 ; i < k ; i++) ans += (happiness[i] - i) >= 0 ? (happiness[i] - i) : 0;
        return ans;
    }
};