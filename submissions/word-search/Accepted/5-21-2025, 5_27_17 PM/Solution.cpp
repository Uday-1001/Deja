// https://leetcode.com/problems/word-search

class Solution {
public:
    bool solve(vector<vector<char>>& board , int i  , int j , string &word , int index , int n , int m)
    {
        //base case
        if(index >= word.size())
        {
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] == '$' || board[i][j] != word[index])
        {
            return false;
        }
        //ek case hum solve karenge 
        char temp = board[i][j];
        board[i][j] = '$';

        //explore all the directions for the word
        bool ans = solve(board , i+1 , j , word , index+1 , n , m) ||
                   solve(board , i-1 , j , word , index+1 , n , m) ||
                   solve(board , i , j+1 , word , index+1 , n , m) ||
                   solve(board , i , j-1 , word , index+1 , n , m);

        //bakctracking pr revert the changes
        board[i][j] = temp;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j] == word[0] && solve(board , i , j , word , 0 , n , m))
                {
                    return true;
                }
            }
        }
        return false;
    }
};