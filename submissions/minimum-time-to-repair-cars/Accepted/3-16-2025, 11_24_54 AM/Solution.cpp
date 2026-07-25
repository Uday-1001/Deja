// https://leetcode.com/problems/minimum-time-to-repair-cars

class Solution {
public:
    bool ispossible(vector<int>& ranks, int cars, long long mid)
    {
        long long repaired_cars = 0;
        for(int i =0  ; i<ranks.size() ;i++)
        {
            int rank = ranks[i];
            repaired_cars += sqrt(mid / rank);
                
            if(repaired_cars >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long s = 1;
        int hr = *max_element(ranks.begin() , ranks.end());
        long long e = (long long)hr * cars * cars;
        long long ans = -1;

        while(s<=e)
        {
            long long mid = s +(e-s)/2;
            if(ispossible(ranks,cars,mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        } 
    return ans;
    }
};