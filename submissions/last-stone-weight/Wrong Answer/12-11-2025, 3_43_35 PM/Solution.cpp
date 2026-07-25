// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto stone : stones) pq.push(stone);
        
        if(pq.size() == 1) return pq.top();
        
        while(pq.size() > 1)
        {
            int first = pq.top(); pq.pop();
            int second = pq.top() ; pq.pop();
            
            if(first != second)
            {
                int left = first-second;

                pq.push(left);
            }
        }
    return pq.top();
    }
};