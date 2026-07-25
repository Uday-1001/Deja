// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total_beauty = 0;

        for(int i=0 ;i<n ; i++)
        {
            std::array<int , 26>hash = {0};
            for(int j = i; j<n ;j++)
            {
                hash[s[j] - 'a']++;

                int min_freq = INT_MAX;
                int max_freq = INT_MIN;

                for(int k=0 ; k<26 ; k++)
                {
                    if(hash[k] > 0)
                    min_freq = min(min_freq , hash[k]);
                    max_freq = max(max_freq , hash[k]);
                }
                int beauty = (max_freq - min_freq);
                total_beauty += beauty;
            }
        }
    return total_beauty;
    }
};