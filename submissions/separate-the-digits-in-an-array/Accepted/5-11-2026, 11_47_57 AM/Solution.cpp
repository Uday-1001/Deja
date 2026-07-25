// https://leetcode.com/problems/separate-the-digits-in-an-array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        string str = "";
        for(auto it : nums) str += to_string(it);

        for(auto it : str) ans.push_back(it - '0');
        return ans;
    }
};