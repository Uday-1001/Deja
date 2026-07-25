// https://leetcode.com/problems/n-queens

class Solution {
public:
    unordered_map<int , bool>rowcheck;
    unordered_map<int , bool>upperdiagonalcheck;
    unordered_map<int , bool>lowerdiagonalcheck;

    bool isSafe(int row , int col , vector<vector<char>>&board)
    {
        if(rowcheck[row] == true || upperdiagonalcheck[row - col] == true || lowerdiagonalcheck[row + col] == true)
        {
            return false;
        }
        //yha aayega valid case 
        return true;
    }

    void storeBoard(vector<vector<string>>&ans ,vector<vector<char>>&board , int col , int n)
    {
        vector<string>temp;
        for(int row =0 ; row<n ; row++)
        {
            string output = "";
            for(int col =0 ; col<n  ; col++)
            {
                output.push_back(board[row][col]);
            }
        temp.push_back(output);
        }
    ans.push_back(temp);
    }

    void solve(vector<vector<string>>&ans ,vector<vector<char>>&board , int col , int n)
    {
        //base case 
        if(col >= n)
        {
            storeBoard(ans , board , col , n);
            return;
        }
        //ek case humne solve kiya hai 
        //baaki ka kaam recursion bhaioya karenge.
        for(int row =0; row<n ; row++)
        {
            //to rakh sakte hai is cell me queen ko but checkl karna padega ki kya ye safe hai
            if(isSafe(row , col , board))
            {
                board[row][col] = 'Q';
                rowcheck[row] = true;
                upperdiagonalcheck[row - col] = true;
                lowerdiagonalcheck[row + col] = true;
                //recursive call jayengi
                solve(ans , board , col+1 , n);
             
                //backtrack kr jana kyuki peeche galti hui hai queen placement me 
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
        
        solve(ans , board , col , n);
        return ans ;
    }
};