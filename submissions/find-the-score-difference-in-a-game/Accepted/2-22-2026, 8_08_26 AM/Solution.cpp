// https://leetcode.com/problems/find-the-score-difference-in-a-game

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score1 = 0 , score2 = 0;

        bool isfirst = true;

        for(int i =0; i<nums.size() ; i++){
            if(nums[i] % 2 == 1)
            {
                isfirst = !isfirst;
            }
            if((i+1) % 6 == 0) isfirst = !isfirst;

            if(isfirst)
            {
                score1 += nums[i];
            }
            else score2 += nums[i];
        }
    return score1 - score2;
    }
};