// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& meetings) {
        vector<vector<int>>ans;
        sort(meetings.begin(), meetings.end());
        int start = meetings[0][0];
        int end = meetings[0][1];
        
        for(int i = 1 ; i<meetings.size() ; i++)
        {
            int left = meetings[i][0];
            int right = meetings[i][1];
            //overlapping condition
            if(end >= left)
            {
                end = max(end,right); 
            }
            else 
            {
                ans.push_back({start,end});   
                start = left;
                end = right;
            }
        }
        ans.push_back({start,end}); 
        return ans;  

    }
};