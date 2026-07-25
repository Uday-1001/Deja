// https://leetcode.com/problems/minimum-discards-to-balance-inventory

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int d = 0;
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        while(j < w){
            mp[arrivals[j]]++;
            if(mp[arrivals[j]] > m){
                mp[arrivals[j]]--;
                arrivals[j] = -1;
                d++;
            }
            j++;
        }
        while(j  < arrivals.size()){
            if(arrivals[i] != -1){
                mp[arrivals[i]]--;
            }
            i++;

            mp[arrivals[j]]++;
            if(mp[arrivals[j]] > m){
                mp[arrivals[j]]--;
                arrivals[j] = -1;
                d++;
            }
            j++;

        }
        return d;
    }
};