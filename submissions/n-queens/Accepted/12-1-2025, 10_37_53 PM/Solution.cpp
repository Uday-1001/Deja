// https://leetcode.com/problems/n-queens

class Solution {
public:
    unordered_map<int , bool>rowcheck;
    unordered_map<int , bool>upperdiagonalcheck;
    unordered_map<int , bool>lowerdiagonalcheck;


    //To check whether the cell is safe for the queen to be placed 
    bool isSafe(int row , int col , vector<vector<char>>&board)
    {
        if(rowcheck[row] == true || upperdiagonalcheck[row - col] == true || lowerdiagonalcheck[row + col] == true)
        {
            return false;
        }
    return true;   
    }

    //To store the final output board
    void StoredBoard(vector<vector<string>>&ans , vector<vector<char>>&board , int n)
    {
        vector<string>temp;
        for(int i=0 ; i<n ; i++)
        {
            string output_of_1line = "";
            for(int j=0 ; j<n ; j++)
            {
                char cell = board[i][j];
                output_of_1line.push_back(cell);
            }
            temp.push_back(output_of_1line);
        }
        ans.push_back(temp);
    }

    //To solve for each row and col and thus check for the possibilities of Recursion
    void solve(vector<vector<string>>&ans , vector<vector<char>>&board , int col , int n)
    {
        //base case 
        if(col >= n)
        {
            StoredBoard(ans , board , n);
            return;
        }
        //ek case hum solve karenge baaki ka recursion dekhlega 
        for(int row = 0 ; row<n ; row++)
        {
            if(isSafe(row , col , board))
            {
                board[row][col] = 'Q';
                rowcheck[row] = true;
                upperdiagonalcheck[row - col] = true;
                lowerdiagonalcheck[row + col] = true;

                solve(ans , board , col+1 , n);

                //backtrack if not possible to put the queen in any of the furthur areas
                board[row][col] = '.';
                rowcheck[row] = false;
                upperdiagonalcheck[row - col] = false;
                lowerdiagonalcheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n , vector<char>(n , '.'));
        vector<vector<string>>ans;

        solve(ans , board , 0 , n);
        return ans;
    }
};