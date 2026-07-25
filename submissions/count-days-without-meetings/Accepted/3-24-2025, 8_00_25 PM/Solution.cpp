// https://leetcode.com/problems/count-days-without-meetings

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
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
        //counting the non working days
        int count = 0;
        for(int i = 1  ; i<ans.size() ; i++)
        {
            count += ans[i][0] - ans[i-1][1] - 1;
        }
        count += days - ans[ans.size()-1][1];
        count += ans[0][0]-1; 
    return count;
    }
};