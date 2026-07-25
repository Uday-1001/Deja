// https://leetcode.com/problems/count-number-of-trapezoids-i

class Solution {
public:
    const int mod = 1e9+7;
    long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    r = min(r, n - r);  

    long long ans = 1;
    for(int i = 1; i <= r; i++) 
    {
        ans = ans * (n - r + i) / i;
    }
    return ans;
}
    int countTrapezoids(vector<vector<int>>& points) {
        int trapezoids = 0;
        int horizontals = 0;
        int verticals = 0;

        for(int i=0 ; i<points.size() ; i++)
        {
            if(points[i][1] == 0) horizontals++;
            else verticals++;
        }

        int possible_hori_combo = (nCr(horizontals , 2)) % mod;
        int possible_verti_combo = (nCr(verticals , 2)) % mod;

        trapezoids = (possible_hori_combo * possible_verti_combo) % mod;
    return trapezoids;
    }
};