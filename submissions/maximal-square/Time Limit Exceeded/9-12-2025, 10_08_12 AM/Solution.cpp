// https://leetcode.com/problems/maximal-square

class Solution {
public:

    int solve(vector<vector<char>>& matrix , int i , int j , int n , int m , int &ans)
    {
        //base case 
        if(i >= n || j >= m) return 0;

        int right = solve(matrix , i , j+1 , n , m , ans);
        int down = solve(matrix , i+1 , j , n , m, ans);
        int diagonal = solve(matrix , i+1 , j+1 , n , m, ans);

        if(matrix[i][j] == '1')
        {
            int boxes = 1 + min(right , min(diagonal , down));
            ans = max(ans , boxes);
            return boxes;
        }
        else 
            return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        solve(matrix , 0 , 0 , n , m , ans);
        return ans * ans;
    }
};