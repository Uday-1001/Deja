// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    bool isSpecial(int row , int col , vector<vector<int>>&mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        bool ans = true;
        for(int j = 0 ; j<m ; j++)
        {
            if(j != col and mat[row][j] == 1) ans = false;
        }

        for(int i = 0 ; i<n ; i++)
        {
            if(i != row and mat[i][col] == 1) ans = false;
        }
    return ans;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int specials = 0;

        for(int i = 0 ; i<n; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(mat[i][j] == 1)
                {
                    if(isSpecial(i , j , mat)) specials++;
                }
            }
        }
    return specials;
    }
};