// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int  , vector<int>>mp;
        for(int i =0 ; i<nums.size() ; i++)
        {
            mp[nums[i]].push_back(i);
        }

        int sum = 0;
        int ans = INT_MAX;
        for(auto it : mp)
        {
            vector<int> indexes = it.second;
            sort(indexes.begin() , indexes.end());
            if(indexes.size() >= 3)
            {
                sum += abs(indexes[2] - indexes[0]);
                for(int i=1 ; i<3 ; i++)
                {
                    sum += abs(indexes[i] - indexes[i-1]);
                }
                ans = min(ans , sum);
            }
           
        }
        return ans == INT_MAX ? -1 : ans;
    }
};