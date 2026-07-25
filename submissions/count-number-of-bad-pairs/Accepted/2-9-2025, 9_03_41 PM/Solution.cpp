// https://leetcode.com/problems/count-number-of-bad-pairs

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();

        long long total_pairs = (n*(n-1))/2 ;
        long long good_pairs = 0;
        
        unordered_map<long,long> map;
        
        for(long long i = 0; i<n ; i++)
        {
            long long key = nums[i] - i;

            if(map.find(key) != map.end())
            {
                good_pairs += map[key];
            }
            // else if(map[key] > 2)
            // {
            //     return 0;
            // }
            
            map[key]++;
        }
    return (total_pairs - good_pairs);
    }
};