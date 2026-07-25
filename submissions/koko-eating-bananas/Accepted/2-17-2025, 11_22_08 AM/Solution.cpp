// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool IsPossible(vector<int>& piles, int h , int k)
    {
        long long total_hours = 0;
        for(int i = 0 ; i< piles.size() ; i++)
        {
        long long bananas = piles[i];
        total_hours += ceil(bananas / (double)k);
        }
        return (total_hours <= h);
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin() , piles.end());
        int ans = -1;
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(IsPossible(piles , h , mid))
            {
                ans = mid ;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
    return ans ;
    }
};