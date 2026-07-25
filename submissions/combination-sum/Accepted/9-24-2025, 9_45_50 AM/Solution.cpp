// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<int>&temp , vector<int>& candidates, int target , int index)
    {
        //base case 
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;

        //ek case hum solve karenge baaki ka recursion sambhalega
        for(int i = index ; i<candidates.size() ; i++)
        {
            //include
            temp.push_back(candidates[i]);
            solve(ans , temp , candidates , target-candidates[i] , i);
            //backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans , temp , candidates , target , 0);
        return ans;
    }
};