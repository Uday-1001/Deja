// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = bank.size();
        int beam_cnt = 0;
        int prev = 0;

        for(int i=0 ; i<row ; i++)
        {
            int curr = 0;
            for(auto cell : bank[i])
            {
                if(cell == '1') curr++;
            }
            if(curr > 0)
            {
                beam_cnt += prev * curr;
                prev = curr;
            }
        }
        return beam_cnt;
    }
};