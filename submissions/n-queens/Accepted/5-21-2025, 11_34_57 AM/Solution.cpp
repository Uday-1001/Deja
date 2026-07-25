// https://leetcode.com/problems/n-queens

class Solution {
public:
    unordered_map<int,bool>rowcheck;
    unordered_map<int,bool>upperdiagonalcheck;
    unordered_map<int,bool>lowerdiagonalcheck;

    bool isSafe(int row , int col , vector<vector<char>>&chessboard)
    {
        if(rowcheck[row] == true || upperdiagonalcheck[row - col] == true || lowerdiagonalcheck[row + col] == true)
        {
            return false;
        }
        //valid case yha hai
        return true;
    }

    void storeboard(vector<vector<string>>&ans , vector<vector<char>>&chessboard , int n)
    {
        vector<string>temp;
        for(int i = 0 ; i<n ; i++)
        {
            string output_col = "";
            for(int j= 0 ; j<n ; j++)
            {
                //yha pe hum log ek cell pe hai
                output_col.push_back(chessboard[i][j]);
            }
            temp.push_back(output_col);
        }
        //yha pe full board aayega kyuki hum dono rows and col traverse kar chuke hai
        ans.push_back(temp);
    }

    void solve(vector<vector<string>>&ans , vector<vector<char>>&chessboard , int col , int n)
    {
        //base case 
        if(col >= n)
        {
            storeboard(ans , chessboard , n);
            return ;
        }
        //ek case hum solve karenge baaki ka recursion bhaiya dekhenge
        for(int row =0 ; row<n ; row++)
        {
            if(isSafe(row, col , chessboard))
            {
                //agar safe hai to place kardo 
                chessboard[row][col] = 'Q';
                rowcheck[row] = true;
                upperdiagonalcheck[row - col] = true;
                lowerdiagonalcheck[row + col] = true;
                //baaki ka recursion dekhega
                solve(ans , chessboard , col+1 , n);
                //agar yha pe aaae ho to matlab ki hum queen place nhi kar pae kyuki pichla ans galat tha 
                //backtrack
                chessboard[row][col] = '.';
                rowcheck[row] = false;
                upperdiagonalcheck[row - col] = false;
                lowerdiagonalcheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>chessboard(n , vector<char>(n , '.'));

        int col =0;

        solve(ans , chessboard , col , n);
        return ans; 
    }
};