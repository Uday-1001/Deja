// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int path = 0;
    void byrec(int m  , int n , int i , int j)
    {
        //base case
        if(i > m or j > n) return;
        if(i == m-1 and j == n-1)
        {
            path++;
            return;
        } 
        //down
        byrec(m , n , i+1 , j);
        //right
        byrec(m , n , i , j+1);
    }

    int uniquePaths(int m, int n) {
        byrec(m , n , 0 , 0);
        return path;
    }
};