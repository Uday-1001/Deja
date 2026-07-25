// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>&ans , int target , vector<int>&temp , int index)
    { 
        //base case 
        if(target == 0)
        {
            ans.push_back(temp);
            return ;
        }
        if(target < 0) return;
        //ek case hum solve karenge 
        for(int i = index ; i<candidates.size() ; i++)
        {
            int candidate = candidates[i];
            //include
            temp.push_back(candidate);
            solve(candidates , ans , target - candidate , temp , i);

            //backtracking
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(candidates , ans , target , temp , 0);
        return ans;
    }
};