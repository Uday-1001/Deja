// https://leetcode.com/problems/total-score-of-dungeon-runs

class Solution {
public:
    int binarysearch(int j, int target, vector<int>&pref){
        int start = 0;
        int end = j;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            if(target >= -pref[mid])
            {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        vector<int> pref(damage.size()+1,0);

        pref[0] = 0;
        pref[1] = damage[0];

        for(int i=2; i<=damage.size(); i++)
        {
            pref[i] = pref[i-1] + damage[i-1];
        }

        long long ans = 0;
        for(int j = 0; j < requirement.size(); j++)
        {
            long long target = hp - pref[j+1] - requirement[j];
            int valid_idx = binarysearch(j,target,pref);
            ans += (valid_idx == -1) ? 0 : j-valid_idx+1;
        }
        return ans;
    }
};