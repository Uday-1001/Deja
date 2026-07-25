// https://leetcode.com/problems/smallest-pair-with-different-frequencies

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
       map<int,int>mp;

       for(auto it : nums) mp[it]++;

       for(auto it1 = mp.begin() ; it1 != mp.end() ; it1++)
       {
            for(auto it2 = next(it1) ; it2 != mp.end() ; it2++)
            {
                if(it1->second != it2->second)
                {
                    return {it1->first , it2->first};
                }
            }
       }
    return {-1,-1};
    }
};