// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int count = 0;
        int max_freq = 0;
        int maxlen = 0;
        unordered_map<int,int>hash;

        for(int r=0 ; r<fruits.size() ; r++)
        {
            hash[fruits[r]]++;

            if(hash.size() > 2)
            {
                hash[fruits[l]]--;
                if(hash[fruits[l]] == 0) hash.erase(fruits[l]);
                l++;
            }
            if(hash.size() <= 2)
            {
                maxlen = max(maxlen , r-l+1);
            }
        }
    return maxlen;
    }
};