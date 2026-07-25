// https://leetcode.com/problems/n-queens

class Solution {
public:
    // to get the valid cells in O(1) time complexity
    unordered_map<int,bool>rowchecker;
    unordered_map<int,bool>upperdiagonalchecker;
    unordered_map<int,bool>lowerdiagonalchecker;
    
    bool isSafe(int row  , int col , vector<vector<char>>&board)
    {
        //check for row , upper diagonal and lower diagonal
        if(rowchecker[row] == true || upperdiagonalchecker[row - col] == true || lowerdiagonalchecker[row+col] == true)
        {
            return false;
        }
        //valid case yha pe sirf
        return true;
    }

    void storeArrangement(vector<vector<string>>&ans , vector<vector<char>>&board , int n ,int col)
    {
        vector<string>temp;
        for(int row =0 ; row<n ; row++)
        {
            string col_output ="";
            for(int col = 0 ; col<n ; col++)
            {
                col_output.push_back(board[row][col]);
            }
            //har col ka output har row ke liye 
        temp.push_back(col_output);
        }
    //final board ka poora nasksha aayega yha
    ans.push_back(temp);
    }

    void solve(int n , vector<vector<string>>&ans , vector<vector<char>>&board , int col)
    {
        // base case 
        if(col >= n)
        {
            // queens humne successfully place krdi hai
            // to ye ke answer hai aur ise store krlo
            storeArrangement(ans, board , n , col);
            return ;
        }
        //ek case hume solve krna hai aur baaki ka kaam recursion dekhega 
        for(int row =0 ; row<n ; row++)
        {
            if(isSafe(row , col , board))
            {   
                board[row][col] = 'Q';
                rowchecker[row] = true;
                upperdiagonalchecker[row - col] = true;
                lowerdiagonalchecker[row + col] = true;
                //recursive call krdo saare aage kaam ke liye 
                solve(n , ans , board , col+1);

                //ek baar jab function return hoga to saare changes ko revert kardena 
                //backtracking 
                board[row][col] = '.';
                rowchecker[row] = false;
                upperdiagonalchecker[row - col] = false;
                lowerdiagonalchecker[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n , vector<char>(n,'.'));

        int col = 0;
        solve(n , ans , board , col);
        return ans;
    }
};