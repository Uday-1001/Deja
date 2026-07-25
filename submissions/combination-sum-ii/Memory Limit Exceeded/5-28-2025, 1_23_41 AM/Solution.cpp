// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>&ans , int target , vector<int>&temp , int index )
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
            solve(candidates , ans , target - candidate , temp , i+1);

            //backtracking
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates) , end(candidates));

        vector<vector<int>>ans;
        vector<int>temp;

        int index = 0;

        solve(candidates , ans , target , temp , index);

        set<vector<int>>st;
        for(auto vec : ans)
        {
            st.insert(vec);
        }

        ans.clear();
        for(auto e : st)
        {
            ans.push_back(e);
        }
        return ans;
    }
};