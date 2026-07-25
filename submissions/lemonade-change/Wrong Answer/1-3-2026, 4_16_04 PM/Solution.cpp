// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivechange = 0;
        int tenchange = 0;
        bool ans = true;

        for(int i = 0 ; i<bills.size() ; i++)
        {
            if(bills[i] == 5) fivechange++;
            else if(bills[i] == 10)
            {
                if(fivechange == 0) ans = false;
                else
                {
                    fivechange--;
                    tenchange++;
                }   
            }
            else 
            {
                if(fivechange == 0 or tenchange == 0) ans = false;
                else 
                {
                    tenchange--;
                    fivechange--;
                }
            }
        }
    return ans;
    }
};