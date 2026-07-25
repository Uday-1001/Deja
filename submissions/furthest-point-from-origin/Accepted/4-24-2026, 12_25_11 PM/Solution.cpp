// https://leetcode.com/problems/furthest-point-from-origin

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0 , right = 0;

        for(auto ch : moves)
        {
            if(ch == 'L') 
            {
                left++;
                right--;
            }
            else if(ch == 'R') 
            {
                right++;
                left--;
            }
            else 
            {
                left++;
                right++;
            }
        }
        return max(left , right);
    }
};