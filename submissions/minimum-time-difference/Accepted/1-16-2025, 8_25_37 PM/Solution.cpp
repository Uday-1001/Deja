// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int convertToMin( string &time)
    {
        int hour = stoi(time.substr(0,2));
        int minutes = stoi(time.substr(3,2));

        return (hour*60) + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;;

        for(auto time : timePoints)
        minutes.push_back(convertToMin(time));

        sort(minutes.begin() , minutes.end());

        int ans = INT_MAX;
        for(int i=0 ; i< minutes.size()-1 ; i++)
        {
            ans = min(ans , minutes[i+1] - minutes[i]);
        }

        int lastdiff = 1440 + minutes[0] - minutes[minutes.size()-1];
        ans = min(ans , lastdiff);

        return ans ;
    }
};