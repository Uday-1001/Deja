// https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution {
public:
    #define pairing pair<int,int>

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();

       vector<pairing>markings(m*n+1);

       vector<int>row(n,0);
       vector<int>col(m,0);
 
       for(int i = 0 ; i<n ;i++)
        {
            for(int j =0; j<m; j++)
            {
                markings[mat[i][j]] = make_pair(i,j);
            }
        }

        for(int i = 0 ; i<m*n ; i++)
        {
            pairing coordinate = markings[arr[i]];

            int x = coordinate.first;
            int y = coordinate.second;

            row[x]++;
            col[y]++;

            if(row[x] == m or col[y] == n)
            {
                return i;
            } 
        }
    return -1; 
    }
};