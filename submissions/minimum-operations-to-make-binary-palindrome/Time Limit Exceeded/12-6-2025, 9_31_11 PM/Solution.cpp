// https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome

class Solution {
public:
    string toBinary(int x) {
        string s;
        while (x > 0) {
            s.push_back((x & 1) ? '1' : '0');
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    bool isBinaryPalindrome(int x) {
    string b = toBinary(x);
    return b == string(b.rbegin(), b.rend());
}

    vector<int> minOperations(vector<int>& nums) {
    vector<int> pal;

    // Precompute all binary palindromes up to a safe range
    for (int i = 1; i <= 100000; i++)
        if (isBinaryPalindrome(i)) pal.push_back(i);

    vector<int> ans(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];

        auto it = lower_bound(pal.begin(), pal.end(), x);
        int best = INT_MAX;

        if (it != pal.end()) best = min(best, abs(*it - x));
        if (it != pal.begin()) best = min(best, abs(*prev(it) - x));

        ans[i] = best;
    }
    return ans;   
    }
};