// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    unordered_map<int , bool>rowcheck;
    unordered_map<int , bool>upperdiagonalcheck;
    unordered_map<int , bool>lowerdiagonalcheck;
    int count = 0;

    bool isSafe(int row , int col)
    {
        if(rowcheck[row] == true || upperdiagonalcheck[row - col] == true || lowerdiagonalcheck[row + col] == true)
        {
            return false;
        }
        //yha aayega valid case 
        return true;
    }

    void solve(int col , int n)
    {
        //base case 
        if(col >= n)
        {
            count++;
            return;
        }
        //ek case humne solve kiya hai 
        //baaki ka kaam recursion bhaioya karenge.
        for(int row =0; row<n ; row++)
        {
            //to rakh sakte hai is cell me queen ko but check karna padega ki kya ye safe hai
            if(isSafe(row , col))
            {
                rowcheck[row] = true;
                upperdiagonalcheck[row - col] = true;
                lowerdiagonalcheck[row + col] = true;
                //recursive call jayengi
                solve(col+1 , n);
             
                //backtrack kr jana kyuki peeche galti hui hai queen placement me 
                rowcheck[row] = false;
                upperdiagonalcheck[row - col] = false;
                lowerdiagonalcheck[row + col] = false;
            }
        }
    } 
    
    int totalNQueens(int n) {
        int col = 0;
        
        solve(col , n);
        return count ;
    }
};