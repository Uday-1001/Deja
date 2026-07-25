// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>occurence;

        for(int i = 0 ; i<nums.size() ; i++) if(nums[i] == x) occurence.push_back(i);

        vector<int>ans;
        for(auto it : queries)
        {
            if(it > occurence.size()) ans.push_back(-1);
            else ans.push_back(occurence[it-1]);
        }
        return ans;
    }
};