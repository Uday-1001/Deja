// https://leetcode.com/problems/maximum-score-from-removing-stones

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxheap;

        maxheap.push(a);
        maxheap.push(b);
        maxheap.push(c);

        int score = 0;
        while(maxheap.size() != 1)
        {
            int topmost = maxheap.top();
            maxheap.pop();
            int second_topmost = maxheap.top();
            maxheap.pop();

            if(topmost == 0 || second_topmost == 0) break;
            score ++;

            topmost--;
            second_topmost--;

            maxheap.push(topmost);
            maxheap.push(second_topmost);
        }
    return score;
    }
};