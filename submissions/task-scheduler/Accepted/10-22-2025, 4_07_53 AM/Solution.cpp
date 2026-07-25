// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int time = 0;

        for(auto ch : tasks) mp[ch]++;

        priority_queue<int>pq;

        for(auto it : mp) pq.push(it.second);

        while(!pq.empty())
        {
            vector<int>cooldown;
            //store the current task and the "n" no of tasks after it -> so it becomes n+1
            for(int i=1 ; i<=n+1 ; i++)
            {
                //whenever the pq is empty , then do not do anything -> CPU is Idle for this iteration
                if(!pq.empty())
                {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    cooldown.push_back(freq);
                }    
            }
            //in case of 0 freq , pq will remain empty and only the size of the array will be added in time
            for(auto &freq : cooldown)
            {
                if(freq > 0)
                {
                    pq.push(freq);
                }
            }
            //addition of time for the answer according to the maxheap
            if(pq.empty())
            {
                time += cooldown.size();
            }
            else
                time += n+1;
        }
    return time;
    }
};