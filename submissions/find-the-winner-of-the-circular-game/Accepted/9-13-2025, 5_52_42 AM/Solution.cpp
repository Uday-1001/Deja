// https://leetcode.com/problems/find-the-winner-of-the-circular-game

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;

        for(int i=1 ; i<=n ; i++)
        {
            q.push(i);
        }

        int reset = k;

        while(q.size() != 1)
        {
            int front = q.front();
            q.pop();
            k--;

            if(k != 0)
            {
                q.push(front);
            }
            else
                k = reset;
        }
    return q.front();    
    }
};