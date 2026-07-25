// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

class Solution {
public:
    bool hasSameDigits(string s) {
        queue<char>q;

        for(auto ch : s) q.push(ch);

        while(q.size() != 2)
        {
            int repeat = q.size()-1;
            while(repeat--)
            {
                int front = q.front()-'0';
                q.pop();
                int next_front = q.front()-'0';

                int sum = (front + next_front) % 10;
                q.push(sum + '0');
            }
            if(!q.empty()) q.pop();
        }

        string ans ="";
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans[0] == ans[1];
    }
};