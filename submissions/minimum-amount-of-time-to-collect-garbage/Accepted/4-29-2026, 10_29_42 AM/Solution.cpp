// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();

        unordered_map<char , pair<int,int>>mp;
        int countG = 0 , countP = 0 , countM = 0;
        int lastG = 0 , lastP = 0 , lastM = 0;

        mp['G'] = {countG , lastG};
        mp['P'] = {countP , lastP};
        mp['M'] = {countM , lastM};

        vector<int>cum_time(n , 0);
        cum_time[0] = travel[0];

        for(int i = 1 ; i<n ; i++) cum_time[i] = cum_time[i-1] + travel[i];

        for(int i = 0 ; i<garbage.size() ; i++)
        {
            string curr = garbage[i];
            for(int j = 0 ; j<curr.size() ; j++)
            {
                int type = curr[j];
                if(type == 'G') mp['G'] = {++countG , i};
                else if(type == 'P') mp['P'] = {++countP , i};
                else mp['M'] = {++countM , i};
            }
        }

        int total = 0;
        for(auto it : mp)
        {
            auto[count , pos] = it.second;
            total += (pos-1) < 0 ? 0 : cum_time[pos-1];
            total += count;
        }
        return total;
    }
};