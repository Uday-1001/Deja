// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;

        int left_max_ht = 0;
        int right_max_ht = 0;

        int water_trapped = 0;

        while(left <= right)
        {
            if(heights[left] > heights[right])
            {
                left_max_ht = max(left_max_ht , heights[left]);
                left++;
            }
            else
            {
                water_trapped += (right_max_ht - heights[right]);
                right_max_ht = max(right_max_ht , heights[right]);
                right--;
            }
        }
    return water_trapped;
    }
};