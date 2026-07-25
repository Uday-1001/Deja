// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    using ll = long long;
    bool isValid(vector<int>&piles , int mid , int h)
    {
        ll total_hours = 0;
        for(int i = 0 ; i<piles.size() ; i++)
        {
            total_hours += ceil(piles[i] / (double)mid);
        }
        return (total_hours <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        ll s = 1;
        ll e = *max_element(begin(piles) , end(piles));

        int ans = -1;
        while(s <= e)
        {
            ll mid = s + (e-s)/2;
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