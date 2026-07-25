// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int max_candy = *max_element(candies.begin() , candies.end());
        for(auto curr :candies)
        {
            if(curr + extraCandies >= max_candy) 
                ans.push_back(true);
            else
                ans.push_back(false);
        }
    return ans;
    }
};