// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

class Solution {
public:
    string operation(string &s)
    {
        queue<char>q;
        for(auto ch : s) q.push(ch);

        string ans = "";

        int repeat = s.size()-1;
        while(q.size()>=2 && repeat--)
        {
            int front = q.front() - '0'; 
            q.pop();
            int next_front = q.front() - '0';
            
            int sum = (front + next_front) % 10;
            q.push(sum + '0');
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
    bool hasSameDigits(string s) {
        string check = operation(s);
        return check[0] == check[1];
    }
};