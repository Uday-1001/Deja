// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n-1;

        int maxwater = 0;
        while(i < j){
            int water = ((min(height[i] , height[j])) * (j-i));
            maxwater = max(maxwater , water);
            
            if(height[i] < height[j]) i++;
            else j--;
        }
    return maxwater;
    }
};