// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int maxi = 0;

        for(int i = 0 ; i<gain.size() ; i++) 
        {
            highest += gain[i];
            maxi = max(maxi , highest);
        }
        return maxi;
    }
};