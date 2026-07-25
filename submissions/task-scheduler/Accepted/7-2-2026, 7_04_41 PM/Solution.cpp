// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;

        for(auto it : tasks) mp[it]++;

        int maxfreq = INT_MIN;
        for(auto it : mp) maxfreq = max(maxfreq , it.second);

        int tasksWithMaxFreq = 0;
        for(auto it : mp) if(it.second == maxfreq) tasksWithMaxFreq++;

        int needed_slots = (maxfreq-1) * (n+1);
        int extra_slots_due_to_tasksWithMaxFreq = tasksWithMaxFreq;

        int total_slots = needed_slots + extra_slots_due_to_tasksWithMaxFreq;

        return max(total_slots , (int)tasks.size());
    }
};