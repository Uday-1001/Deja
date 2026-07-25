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
                if(fivechange > 0)
                {
                    fivechange--;
                    tenchange++;
                }
                else return false;   
            }
            else 
            {
                if(tenchange > 0 and fivechange > 0)
                {
                    tenchange--;
                    fivechange--;
                }
                else if(fivechange >= 3) fivechange -= 3;
                else return false;
            }
        }
    return ans;
    }
};