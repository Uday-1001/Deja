// https://leetcode.com/problems/combinations

class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<int>&curr , int i , int n , int k)
    {
        //base case 
        if(k == 0)
        {
            ans.push_back(curr);
            return;
        }
        //ek case hum solve karenge baaki recursion sambhalega
        for(int j = i ; j<=n ; j++)
        {
            curr.push_back(j);

            solve(ans , curr , j+1 , n , k-1);

            //backtracking
            curr.pop_back();        
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;

        vector<int>curr;
        solve(ans , curr , 1 , n , k);

        return ans;
    }
};