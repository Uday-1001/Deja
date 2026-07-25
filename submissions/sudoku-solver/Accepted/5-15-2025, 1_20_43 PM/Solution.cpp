// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    bool isSafe(int i , int j , char digit , vector<vector<char>>& board)
    {
        //row check
        //col check
        //3*3 sub-boxes check
        int n = board.size();
        for(int k = 0 ; k<n ;k++)
        {
            //agar pehle se koi same digit row me padi hui hai
            if(board[i][k] == digit)
            {
                return false;
            }
        }
        for(int k = 0 ; k<n ;k++)
        {
            //agar pehle se koi same digit col me padi hui hai
            if(board[k][j] == digit)
            {
                return false;
            }
        }
        for(int k = 0 ; k<n ;k++)
        {
            //agar pehle se koi same digit 3*3 sub box me padi hui hai
            if(board[3*(i/3)+k/3][3*(j/3)+k%3] == digit)
            {
                return false;
            }
        }
    //agar koi valid case hai to yha aana hai
    return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i =0 ; i<board.size() ; i++)
        {
            for(int j =0; j<board[0].size() ; j++)
            {
                //yha pe hum i,jth space pe hai
                //to hum kya yha pe digit fill kre?
                //agar '.' hai to 1 -> 9 tk fill kro
                if(board[i][j] == '.')
                {
                    for(char digit='1' ; digit<='9' ; digit++)
                    {
                        if(isSafe(i,j,digit,board))
                        {
                            //agar safe hai to place krdo digit ko
                            board[i][j] = digit;
                            //aage ka kaam recursion ka hai...
                            bool aageKaAns = solve(board);
                            if(aageKaAns == true)
                            {
                                return true;
                            }
                            else
                            {
                                //backtrack krlo vapis kyuki peeche khi galti ki hai
                                board[i][j] = '.';
                            }
                        }   
                    }
                    //yha tab aaoge jab tum 1 se 9 tk koi digit place nhi krpae us cell me
                    //iska matlab answer nhi mil sakta aise
                    return false;
                }
            }
        }
        //yha tab aaoge jab poora board traverse ho chuka hai aur tumhe ek bhi invalid answer nhi mila hai aur successfully fill ho chuka hai 
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);

    }
};