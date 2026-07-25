// https://leetcode.com/problems/sequential-digits

class Solution {
public:
    vector<int>ans;
    void solve(int num , int nextdigit , int low , int high)
    {
        if(nextdigit > 9) return;
        int newnumber = num * 10 + nextdigit;

        if(newnumber > high) return;

        if(newnumber >= low) ans.push_back(newnumber);

        solve(newnumber , nextdigit+1 , low , high);
    }

    vector<int> sequentialDigits(int low, int high) {
        for(int start = 1 ; start <= 9 ; start++) solve(start , start+1 , low , high);
        sort(begin(ans) , end(ans));  
        return ans;
    }
};