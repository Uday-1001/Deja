// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int dp[301][301];

    int bymemo(vector<vector<char>>& matrix , int i , int j , int n , int m , int &ans)
    {
        //base case 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = bymemo(matrix , i , j-1 , n , m , ans);
        int down = bymemo(matrix , i-1 , j , n , m, ans);
        int diagonal = bymemo(matrix , i-1 , j-1 , n , m, ans);

        if(matrix[i][j] == '1')
        {
            int boxes = 1 + min(right , min(diagonal , down));
            ans = max(ans , boxes);
            return dp[i][j] = boxes;
        }
        else 
            return dp[i][j] = 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp , -1 , sizeof(dp));

        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        bymemo(matrix , n-1 , m-1 , n , m , ans);
        return ans * ans;
    }
};