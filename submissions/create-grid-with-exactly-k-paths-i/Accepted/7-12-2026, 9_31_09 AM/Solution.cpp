// https://leetcode.com/problems/create-grid-with-exactly-k-paths-i

class Solution {
public:
    using ll = long long;
    vector<string>grid;
    vector<vector<ll>>dp;

    ll solve(int i , int j , int m , int n)
    {
        //base case
        if(i >= m or j >= n) return 0;
        if(grid[i][j] == '#') return 0;
        if(i == m-1 and j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i+1 , j , m , n) + solve(i , j+1 , m , n);
    }

    bool canMakeGrid(int i , int j , int m , int n , int k)
    {
        dp.assign(m , vector<ll>(n , -1));

        ll currentpaths = solve(0 , 0 , m , n);
        if(currentpaths == k) return true;
        if(currentpaths < k) return false;

        if(i == m) return false;
        int newr = i;
        int newc = j+1;
        if(newc == n){
            newr = i+1;
            newc = 0;
        }

        if((i == 0 and j == 0) or (i == m-1 and j == n-1))
            return canMakeGrid(newr , newc , m , n , k);

        grid[i][j] = '#';
        if(canMakeGrid(newr , newc , m , n , k)) return true;

        grid[i][j] = '.';
        if(canMakeGrid(newr , newc , m , n , k)) return true;

        return false;
    }
    
    vector<string> createGrid(int m, int n, int k) {
        grid.assign(m , string(n , '.'));

        dp.assign(m , vector<ll>(n , -1));

        ll paths = solve(0 , 0 , m , n);
        if(paths < k) return {};
        if(canMakeGrid(0 , 0 , m , n , k)) return grid;
        return {};
    }
};