// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0;
        int right = n-1;

        int maxi = INT_MIN;

        while(left < right)
        {
            int area = 0;

            int smallest_rod = min(heights[left] , heights[right]);
            int width = right - left;

            maxi = max(maxi , (smallest_rod * width));

            if(heights[left] > heights[right])
                right--;
            else
                left++;
        }
    return maxi;
    }
};