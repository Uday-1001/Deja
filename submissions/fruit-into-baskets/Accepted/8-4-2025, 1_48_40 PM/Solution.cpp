// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;

        int left = 0;
        int right = 0;
        int max_len = 0;
         
        while(right < fruits.size())
        {
            mp[fruits[right]]++;
            if(mp.size() > 2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);               
                }
                left++;
            }
            max_len = max(max_len , right-left+1);
            right++;
        }
    return max_len;
    }
};