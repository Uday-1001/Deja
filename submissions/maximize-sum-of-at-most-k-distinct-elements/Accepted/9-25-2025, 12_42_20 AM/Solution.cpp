// https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto num : nums)
        {
            st.insert(num);
        }

        vector<int>unique(st.begin() , st.end());
        sort(rbegin(unique) , rend(unique));
        vector<int>ans;

        int count = 0;
        for(auto num: unique)
        {
            if(count == k) break;
            ans.push_back(num);
            count++;
        }
    return ans;
    }
};