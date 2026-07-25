// https://leetcode.com/problems/reveal-cards-in-increasing-order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin() , deck.end());

        vector<int>ans(deck.size() , 0);

        queue<int>q;
        for(int i=0 ; i<deck.size() ; i++)
        {
            q.push(i);
        }

        int i = 0;
        while(!q.empty() && i < deck.size())
        {
            int front = q.front();
            //playing the reverse simulation of the whole process
            //taking the front index of queue and inserting sorted elem at that position.
            ans[front] = deck[i];
            q.pop();

            //calculating the next front, if exists ,and then pushing it back as instructed
            if(!q.empty())
            {
                int next_front = q.front();
                q.push(next_front);
                q.pop();
            }
            i++;
        }
    return ans;
    }
};