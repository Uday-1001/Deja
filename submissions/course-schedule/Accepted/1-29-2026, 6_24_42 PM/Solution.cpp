// https://leetcode.com/problems/course-schedule

class Solution {
public:
    unordered_map<int , vector<int>>adjlist;
    unordered_map<int, bool>vis;
    vector<int>ans;

    void toposort(int n , vector<int>&indegree)
    {
        queue<int>q;
        for(int i = 0 ; i<n ; i++)
        {
            for(auto nbr : adjlist[i]) indegree[nbr]++;
        }

        //maintain the initial state of queue with indegree zero nodes
        for(int i = 0 ; i <n ; i++) if(indegree[i] == 0) q.push(i);

        while(!q.empty())
        {
            int frontnode = q.front(); q.pop();
            ans.push_back(frontnode);

            for(auto &nbr : adjlist[frontnode])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto it : prerequisites) adjlist[it[1]].push_back(it[0]);

        vector<int>indegree(numCourses);
        toposort(numCourses , indegree);

        if(ans.size() == numCourses) return true;
        else return false;
    }
};