// https://leetcode.com/problems/total-score-of-dungeon-runs

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();

        long long sum = 0;
        long long ans = 0;

        int l = 0;
        for(int i=0 ; i < n ; i++){
            sum += damage[i];

            long long bearable_limit = hp - requirement[i];
            while(l <= i and sum > bearable_limit){
                sum -= damage[l];
                l++;
            }
            ans += (i - l + 1);
        }
    return ans;
    }
};