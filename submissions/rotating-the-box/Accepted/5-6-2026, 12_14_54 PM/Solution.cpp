// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>>ansbox(m , vector<char>(n , '.'));
        
        for(int i = 0 ; i<n ; i++)
        {
            int endpt = m-1;
            for(int j = m-1 ; j>=0 ; j--)
            {
                if(boxGrid[i][j] == '*') endpt = j-1;
                else if(boxGrid[i][j] == '#')
                {
                    boxGrid[i][j] = '.';
                    boxGrid[i][endpt--] = '#';
                }
            }
        }
    
        for(int i = 0 ; i<n ; i++) for(int j = 0 ; j<m ; j++) ansbox[j][n - i - 1] = boxGrid[i][j];
        return ansbox;
    }
};