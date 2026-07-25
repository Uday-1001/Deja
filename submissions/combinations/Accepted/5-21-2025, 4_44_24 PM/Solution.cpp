// https://leetcode.com/problems/combinations

class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<int>&temp , int n , int k , int i)
    {
        //base case 
        if(k == 0)
        {
            ans.push_back(temp);
        }

        //ek case hum solve karenge baaki ka kaam recursion ka 
        for(int start = i ; start<=n ; start++)
        {
            temp.push_back(start);
            //recursive call krdo
            solve(ans , temp , n , k-1 , start+1);
            //backtracking to revert the changes done 
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans , temp , n , k , 1);
        return ans;
    }
};