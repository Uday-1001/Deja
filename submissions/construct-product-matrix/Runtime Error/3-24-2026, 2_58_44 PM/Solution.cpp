// https://leetcode.com/problems/construct-product-matrix

class Solution {
public:
    int mod = 12345;
    using ll = long long;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans;
        vector<int>vec;
        vec.resize(n*m , 0);

        int index = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++) vec[index++] = grid[i][j];
        }

        int size = vec.size();

        vector<ll>prefix(size,1);
        vector<ll>suffix(size,1);
        vector<ll>flatans(size);

        for(int i = 1; i < size; i++) prefix[i] = prefix[i-1] * vec[i-1];

        for(int i = size-2; i >= 0; i--) suffix[i] = suffix[i+1] * vec[i+1];

        for(int i = 0 ; i<size ; i++) flatans[i] = (1LL * prefix[i] * suffix[i]) % mod;

        index = 0;
        for(int i = 0 ; i<n ; i++)
        {
            vector<int>temp;
            for(int k = 0 ; k<m ; k++) temp.push_back(flatans[index++] % mod);
            ans.push_back(temp);
        }

        return ans;
    }
};