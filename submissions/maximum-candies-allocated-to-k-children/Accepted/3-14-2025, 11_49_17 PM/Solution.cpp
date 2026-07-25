// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class Solution {
public:
    bool ispossible(vector<int>& candies, long long k , long long mid)
    {
        long long kid_count = 0;
        for(int i = 0; i<candies.size() ; i++)
        { 
            kid_count += candies[i] / mid;
        }
        return (kid_count >= k);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long s = 1;
        long long e = *max_element(candies.begin(), candies.end());
        long long ans = 0;

        while(s<=e){
            long long mid = s + (e-s)/2;
            if(ispossible(candies , k , mid))
            {
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }
    return ans;
    }
};