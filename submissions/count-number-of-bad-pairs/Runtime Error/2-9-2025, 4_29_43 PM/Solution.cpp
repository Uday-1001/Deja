// https://leetcode.com/problems/count-number-of-bad-pairs

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        int total_pairs = (n*(n-1))/2 ;
        int good_pairs = 0;
        
        unordered_map<int,int> map;
        
        for(int i = 0; i<n ; i++)
        {
            int key = nums[i] - i;

            if(map.find(key) != map.end())
            {
                good_pairs += map[key];
            }
            else if(map[key] > 2)
            {
                return 0;
            }
            map[key]++;
        }
    return (total_pairs - good_pairs);
    }
};