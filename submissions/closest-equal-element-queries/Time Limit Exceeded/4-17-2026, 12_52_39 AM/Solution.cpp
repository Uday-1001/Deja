// https://leetcode.com/problems/closest-equal-element-queries

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int , vector<int>>pos;
        for(int i = 0 ; i<nums.size() ; i++) pos[nums[i]].push_back(i);

        vector<int>ans;
        for(auto it : queries)
        {
            int nearest = INT_MAX;
            if(pos[nums[it]].size() == 1)
            {
                ans.push_back(-1);
                continue;
            } 

            int startIndex = it;
            int n = pos[nums[it]].size();
            int m = nums.size();
            
            for(int i = 0 ; i<n ; i++)
            {
                int curridx = pos[nums[it]][i];
                if(curridx == startIndex) continue;

                int forward = (curridx - startIndex + m) % m;
                int backward = (startIndex - curridx + m) % m;

                nearest = min({nearest , forward , backward});   
            }
            ans.push_back(nearest);
        }

        return ans;
    }
};