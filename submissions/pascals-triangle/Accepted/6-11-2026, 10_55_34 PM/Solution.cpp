// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};

        ans.push_back({1});
        ans.push_back({1 , 1});

        for(int i = 2 ; i<numRows ; i++)
        {
            vector<int>newrow(i+1 , 1);
            for(int j = 1 ; j<i ; j++)
            {
                newrow[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(newrow);
        }
        return ans;
    }
};