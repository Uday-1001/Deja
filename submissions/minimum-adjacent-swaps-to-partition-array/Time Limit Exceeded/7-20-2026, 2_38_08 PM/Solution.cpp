// https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<int> currentIndex(n);

        vector<int> lessThanA;
        vector<int> between;
        vector<int> greaterThanB;

        for(int i = 0 ; i < n ; i++)
        {
            currentIndex[i] = i;

            if(nums[i] < a) lessThanA.push_back(i);
            else if(nums[i] <= b) between.push_back(i);
            else greaterThanB.push_back(i);
        }

        long long swaps = 0;

        for(int i = 0 ; i < lessThanA.size() ; i++)
        {
            int element = lessThanA[i];
            int currPos = currentIndex[element];
            int targetPos = i;

            if(currPos == targetPos) continue;

            swaps += abs(currPos - targetPos);

            for(int j = 0 ; j < n ; j++)
            {
                if(j == element)continue;

                if(currentIndex[j] >= targetPos && currentIndex[j] < currPos) currentIndex[j]++;
            }

            currentIndex[element] = targetPos;
        }

        int startMiddle = lessThanA.size();

        for(int i = 0 ; i < between.size() ; i++)
        {
            int element = between[i];
            int currPos = currentIndex[element];
            int targetPos = startMiddle + i;

            if(currPos == targetPos) continue;

            swaps += abs(currPos - targetPos);

            if(currPos > targetPos)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(j == element) continue;

                    if(currentIndex[j] >= targetPos && currentIndex[j] < currPos) currentIndex[j]++;
                }
            }
            else
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(j == element) continue;

                    if(currentIndex[j] > currPos && currentIndex[j] <= targetPos) currentIndex[j]--;
                }
            }

            currentIndex[element] = targetPos;
        }

        return swaps % MOD;
    }
};