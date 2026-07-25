// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    using pi = pair<int,int>;

    bool isPossible(int x , int y , vector<vector<char>>&board , vector<vector<bool>>&vis)
    {
        int n = board.size();
        int m = board[0].size();

        if(x < 0 or x >= n or y < 0 or y >= m or board[x][y] != 'O' or vis[x][y]) return false;
        return true;
    }

    void BFS(vector<vector<char>>&board , vector<vector<bool>>&vis)
    {
        int n = board.size();
        int m = board[0].size();

        queue<pi>q;
        for(int i = 0 ; i<n; i++)
        {
            if(board[i][0] == 'O' and !vis[i][0]) 
            {
                q.push({i , 0});
                board[i][0] = '%';
                vis[i][0] = true;
                
            }
            if(board[i][m-1] == 'O' and !vis[i][m-1]) 
            {
                q.push({i , m-1});
                board[i][m-1] = '%';
                vis[i][m-1] = true;
            }
        }

        for(int j = 0 ; j<m; j++)
        {
            if(board[0][j] == 'O' and !vis[0][j]) 
            {
                q.push({0 , j});
                board[0][j] = '%';
                vis[0][j] = true;
            }

            if(board[n-1][j] == 'O' and !vis[n-1][j]) 
            {
                q.push({n-1 , j});
                board[n-1][j] = '%';
                vis[n-1][j] = true;
            }
        }

        while(!q.empty())
        {
            auto[row , col] = q.front();
            cout<<row<<"->"<<col<<endl;
            q.pop();

            vector<int>dr = {-1 , 1 , 0 , 0};
            vector<int>dc = {0 , 0 , 1 , -1};

            for(int k = 0 ; k<4 ; k++)
            {
                int newr = row + dr[k];
                int newc = col + dc[k];

                if(isPossible(newr , newc , board , vis))
                {
                    vis[newr][newc] = true;
                    board[newr][newc] = '%';
                    q.push({newr , newc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n , vector<bool>(m , false));
        BFS(board , vis);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(board[i][j] == '%')
                {
                    board[i][j] = 'O';
                }
                else board[i][j] = 'X';
            }
        }
    }
};