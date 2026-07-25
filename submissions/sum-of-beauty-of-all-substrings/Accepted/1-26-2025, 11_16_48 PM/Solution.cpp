// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty_sum = 0;

        unordered_map<char,int> map;

        for(int i = 0 ; i<n ; i++)
        {
            map.clear();
            for(int j =i; j<n ;j++)
            {
                char &ch = s[j];
                map[ch]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;

                for(auto chr : map)
                {
                    maxi = max(maxi , chr.second);
                    mini = min(mini , chr.second);
                }
                int beauty = maxi - mini;
                beauty_sum += beauty;
            }
        }
    return beauty_sum;
    }
};