// https://leetcode.com/problems/two-furthest-houses-with-different-colors

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        
        for(int i = 0 ; i<n ; i++)
        {
            if(colors[0] != colors[i]) ans = max(ans , i);
            if(colors[i] != colors[n-1]) ans = max(ans , abs(n-1-i));   
        }
        
        return ans;
    }
};