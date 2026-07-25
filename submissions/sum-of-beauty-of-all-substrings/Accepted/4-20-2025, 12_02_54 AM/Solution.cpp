// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty_sum = 0;

        for(int i = 0; i<n ; i++)
        {
            // hash map for frequencies
            int hash[26] = {0};

            for(int j = i ; j<n ; j++)
            {
                //entry of each element
                hash[s[j] - 'a']++;
            
                int min_freq = INT_MAX;
                int max_freq = INT_MIN;
                // calculating the min and max freq for each of the substring 
                for(int k = 0 ; k <26 ; k++)
                {
                    if(hash[k] > 0)
                    {
                        min_freq = min(min_freq , hash[k]);
                        max_freq = max(max_freq , hash[k]);
                    }                
                } 
                //sum up the beauty to the beauty sum of each substring 
            beauty_sum += (max_freq - min_freq);
        }
    }
        return beauty_sum;
    }
};