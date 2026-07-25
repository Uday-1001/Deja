// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int MinuteConverter(string &a)
    {
        int hours = stoi(a.substr(0,2));
        int mins = stoi(a.substr(3,2));
        return (hours*60) + mins;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto time : timePoints)
        {
            mins.push_back(MinuteConverter(time));
        }

        sort(mins.begin() , mins.end());

        int ans = INT_MAX;
        for(int i =0  ; i<mins.size()-1 ; i++)
        {
            ans = min(ans , mins[i+1]-mins[i]);
        }

        int from_last_of_clock = 1440 + mins[0] - mins[mins.size()-1];
        ans = min(ans , from_last_of_clock);

        return ans;
    }
};