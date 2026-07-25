// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>ans;
        ans.push_back(1);

        vector<int>greater_one;
        greater_one.push_back(obstacles[0]);

        for(int i = 1 ; i < n ; i++)
        {
            auto just_greater_idx = upper_bound(greater_one.begin() , greater_one.end() , obstacles[i]);
            int len = just_greater_idx - greater_one.begin() + 1;

            if(just_greater_idx == greater_one.end()) greater_one.push_back(obstacles[i]);
            else
            {
                *just_greater_idx = obstacles[i];
            }
            ans.push_back(len);
        }
    return ans;
    }
};