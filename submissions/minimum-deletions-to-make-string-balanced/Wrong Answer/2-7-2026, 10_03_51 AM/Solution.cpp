// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

class Solution {
public:
    int minimumDeletions(string s) {
        int a_count = 0;
        int b_count = 0;
        int ans = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            char ch = s[i];

            if(ch == 'a' and b_count == 0) continue;
            else if(ch == 'b') b_count++;
            else if(ch == 'a' and b_count > 0) a_count++;

            if(a_count > 0 and b_count > 0)
            {
                ans += min(a_count , b_count);
                a_count -= ans , b_count -= ans;
            }
        }
    return ans;
    }
};