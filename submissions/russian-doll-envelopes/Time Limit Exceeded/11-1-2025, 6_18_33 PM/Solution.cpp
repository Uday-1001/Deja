// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    bool isValidToPlace(vector<int>prev , vector<int>curr)
    {
        return (prev[0] < curr[0] && prev[1] < curr[1]);
    }

    int byrec(vector<vector<int>>& envelopes , int prev , int curr)
    {
        if(curr >= envelopes.size()) return 0;

        //ek case hum log check karenge aur solve krdenge 
        int include = 0;
        if(prev == -1 || isValidToPlace(envelopes[prev] , envelopes[curr]))
        {
            include = 1 + byrec(envelopes , curr , curr+1);
        }
        int exclude = 0 + byrec(envelopes , prev , curr+1);

        return max(include , exclude);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end());

        return byrec(envelopes , -1 , 0);
    }
};