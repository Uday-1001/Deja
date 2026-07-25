// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool checkValid(int i , int j , char digit , vector<vector<char>>& board)
    {
        //row checking for the same digit i have 
        for(int col = 0 ; col<9 ; col++)
        {
            if(col != j && board[i][col] == digit)
            {
                return false;
            }
        }

        //col checking for the same digit i have 
        for(int row = 0 ; row<9 ; row++)
        {
            if(row != i && board[row][j] == digit)
            {
                return false;
            }
        }

        //3*3 box checking for the same digit i have 
        int startrow = 3 * (i/3);
        int startcol = 3 * (j/3);

        for(int row = startrow ; row < startrow + 3 ; row++)
        {
            for(int col = startcol ; col < startcol + 3 ; col++)
            {
                if((row != i || col != j) && board[row][col] == digit)
                {
                    return false;
                }
            }
        }
        //any valid case is treated here
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            { 
               char digit = board[i][j];

               if(digit != '.')
                {
                    if(!checkValid(i , j , digit , board))
                    {
                        return false;
                    }
                }
            }
        }
        //this means we have checked every boax and no mistake has been found
        return true;
    }
};