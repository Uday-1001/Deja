// https://leetcode.com/problems/reducing-dishes

class Solution {
public:

    int byrec(vector<int>& satisfaction, int time, int i){
        // base case
        if(i >= satisfaction.size()){
            return 0;
        }
        // include
        int include = (satisfaction[i]*time) + byrec(satisfaction, time+1, i+1);
        // exclude
        int exclude = byrec(satisfaction, time, i+1);

        return max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = byrec(satisfaction, 1, 0);
        return ans;
    }
};