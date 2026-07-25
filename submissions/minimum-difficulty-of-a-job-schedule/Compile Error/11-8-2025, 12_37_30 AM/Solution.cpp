// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:
    int byrec(vector<int>& jobDifficulty, int d , int s , int e)
    {
        if(d < 0) return 0;

        //ek case hum solve karenge
        for(int i=0 ; i<d ; i++)
        {
            int portion_ans = maxInPortion(jobDifficulty , )
        }
        
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        return byrec(jobDifficulty , d , 0);
    }
};