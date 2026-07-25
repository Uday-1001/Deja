// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool ispossible(vector<int>& bloomDay, int m, int k ,int mid)
    {
        int count = 0;
        for(auto flower : bloomDay)
        {
            if(flower <= mid)
            {
                count++;
            }
            if(count == k)
            {
                m--;
                count = 0;
                if(m == 0) break;
            }
            if(flower > mid)
            {
                count = 0;
            } 
        }
    return (m == 0);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1;
        int e = *max_element(begin(bloomDay) , end(bloomDay));
        int ans = -1;

        if(bloomDay.size() < (long long)m * (long long)k) return -1;

        while(s<=e)
        {
            int mid  = s+(e-s)/2;
            if(ispossible(bloomDay , m , k , mid))
            {
                ans = mid;
                e = mid -1 ;
            }
            else
                s = mid +1;
        }
        return ans ;
    }
};