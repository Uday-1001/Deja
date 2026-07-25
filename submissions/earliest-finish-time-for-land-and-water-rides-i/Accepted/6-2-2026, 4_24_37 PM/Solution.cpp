// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                int op1 = max(landStartTime[i] + landDuration[i] , waterStartTime[j]) + waterDuration[j];

                int op2 = max(waterStartTime[j] + waterDuration[j] , landStartTime[i]) + landDuration[i];

                ans = min({ans , op1 , op2});
            }
        }
        return ans;
    }
};