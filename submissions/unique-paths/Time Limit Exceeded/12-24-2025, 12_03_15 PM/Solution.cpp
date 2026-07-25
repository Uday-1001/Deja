// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int byrec(int m  , int n , int i , int j)
    {
        //base case
        if(i > m or j > n) return 0;
        if(i == m-1 and j == n-1) return 1;
        //down
        int down = byrec(m , n , i+1 , j);
        //right
        int right = byrec(m , n , i , j+1);

        return down + right;
    }

    int uniquePaths(int m, int n) {
        return byrec(m , n , 0 , 0);
    }
};