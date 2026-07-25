// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

class Solution {
public:
    int isEnough(vector<vector<int>>& tasks , int s , int e , int mid)
    {
        for(int i = 0 ; i<tasks.size() ; i++)
        {
            int deduction = tasks[i][0];
            int need = tasks[i][1];

            if(mid >= need) mid -= deduction;
            else return false;
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks) , end(tasks));
        
        int s = 0;
        int e = 0;
        for(auto it : tasks) e += it[1];

        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(isEnough(tasks , s , e , mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};