// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rows = bank.size();
        int prev_count =0;
        int ans = 0;

        for(int i =0 ; i<rows ; i++)
        {
            int current_count =0;

            for(auto ch : bank[i])
            if(ch == '1')
            current_count ++;

            if(current_count >0)
            {
                ans += prev_count * current_count ;
                prev_count = current_count ;
            }
        }
    return ans ;
    }
};