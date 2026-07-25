// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int solve(int m , int n , int i , int j)
    {
        if(i > m or j > n) return 0;
        if(i == m-1 and j == n-1) return 1;

        int right = 0 , down = 0;
        cout<<"right = "<<right<<endl;
        cout<<"down = "<<down<<endl;
        if(j < n) down = solve(m , n , i+1 , j);
        cout<<"after down call ------"<<endl;
        cout<<"right = "<<right<<endl;
        cout<<"down = "<<down<<endl;
        if(i < m) right = solve(m , n , i , j+1);

        return right + down;   
    }

    int uniquePaths(int m, int n) {
        return solve(m , n , 0 , 0);
    }
};