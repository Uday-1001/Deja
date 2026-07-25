// https://leetcode.com/problems/n-queens

class Solution {
public:
    unordered_map<int , bool> rowcheck;
    unordered_map<int , bool> upperdiagonalcheck;
    unordered_map<int , bool> lowerdiagonalcheck;
    bool isSafe(int row , int col , vector<vector<char>>&board)
    {
        //check for :-
        //row , upper and lower diagonal
        if(rowcheck[row] == true || upperdiagonalcheck[row - col] == true ||
                 lowerdiagonalcheck[row + col] == true)
        {
            return false;
        }
    return true;
    }

    void storeBoard(vector<vector<string>>&ans , vector<vector<char>>&board , int col , int n)
    {
        vector<string>tempAns;

        for(int row=0 ; row<n ; row++)
        {
            string ans = "";
            for(int col = 0 ; col<n ; col++)
            {
                //yha har col ka answer milega
                ans.push_back(board[row][col]);
            }
            //saare cols traverse krne ke baad sabko store kro aur yhi cheez har row ke liye hogi
            tempAns.push_back(ans);
        }
        //final answer yha banega jab dono row and col traverse ho chuke hai !
        ans.push_back(tempAns);
    }

    void solve(int n , vector<vector<char>>&board , vector<vector<string>>&ans , int col)
    {
        if(col >= n)
        {
            //all queens are placed successfully
            storeBoard(ans , board ,col , n);
            return;
        }
        //ek case hum solve karenge baakii recursion krega 
        for(int row = 0 ; row<n ; row++)
        {
            if(isSafe(row , col , board))
            {
                board[row][col] = 'Q';
                rowcheck[row] = true;
                upperdiagonalcheck[row - col] = true;
                lowerdiagonalcheck[row + col] = true;

                solve(n , board , ans , col+1);

                //function return aane ke baad saare changes ko revert krna padega
                //backtracking
                board[row][col] = '.';
                rowcheck[row] = false;
                upperdiagonalcheck[row - col] = false;
                lowerdiagonalcheck[row + col] = false;
            }
        } 
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n , vector<char>(n,'.'));
        int col = 0;

        solve(n , board , ans , col);
        return ans;
    }
};