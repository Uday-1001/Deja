// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

class Solution {
public:
    char kthCharacter(int k) {
        int len = 1;
        while(len < k)
        {
            len *= 2;
        }
        int shift_needed = 0;
        while(len > 1)
        {
            int half = len / 2;
            if(k > half)
            {
                k = k - half;
                shift_needed ++;
            }
            len = half;
        }

        int result = 'a' + shift_needed;
        if(result > 'k')
        {
            result = result - 26;
        }
        return result;
    }
};