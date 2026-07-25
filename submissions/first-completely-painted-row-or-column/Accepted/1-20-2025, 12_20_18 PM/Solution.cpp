// https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution {
    #define pairing pair<int ,int>
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pairing>lookup(m*n+1);
        for(int i=0 ; i<n ; i++)
        {
            for(int j =0 ; j<m ; j++)
            {
                lookup[mat[i][j]] = make_pair(i,j);          
            }
        }
        vector<int>row_counter(n,0);
        vector<int>col_counter(m,0);

        for(int i=0 ; i<m*n ; i++)
        {
            pairing coordinate = lookup[arr[i]];
            int x = coordinate.first;
            int y = coordinate.second;

            row_counter[x]++;
            col_counter[y]++;

            if(row_counter[x] == m || col_counter[y] == n)
            return i;
        }
    return -1;
    }
};