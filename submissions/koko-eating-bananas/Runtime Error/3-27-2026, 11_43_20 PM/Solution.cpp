// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool isValid(vector<int>&piles , int mid , int h)
    {
        int total_hours = 0;
        for(int i = 0 ; i<piles.size() ; i++)
        {
            total_hours += ceil(piles[i] / (double)mid);
        }
        return (total_hours <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = *max_element(begin(piles) , end(piles));

        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(isValid(piles , mid , h))
            {
                ans = mid;
                e = mid-1;
            }
            else s = mid + 1;
        }
    return ans;
    }
};