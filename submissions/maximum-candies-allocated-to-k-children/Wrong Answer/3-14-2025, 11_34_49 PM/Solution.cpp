// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class Solution {
public:
    bool ispossible(vector<int>& candies, long long k , int mid)
    {
        int kid_count = 0;
        for(int i = 0; i<candies.size() ;i++)
        {
            if(candies[i] / mid) 
                kid_count++;
            if(kid_count >= k)
            return true;
        }
    return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int sum = accumulate(candies.begin(), candies.end() , 0);
        if(sum < k) return 0;

        int s = 1;
        int e = *max_element(candies.begin(), candies.end());
        int ans = -1;

        while(s<=e){
            int mid = s + (e-s)/2;
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