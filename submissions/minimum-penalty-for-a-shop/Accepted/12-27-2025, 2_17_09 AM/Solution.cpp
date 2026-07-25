// https://leetcode.com/problems/minimum-penalty-for-a-shop

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        for(auto ch : customers) if(ch == 'Y') penalty += 1;

        int minpenalty = penalty;
        int best_hour = 0;
        for(int i = 0 ; i < n ; i++)
        {
            char ch = customers[i];
            if(ch == 'Y') 
            {
                penalty--;
                if(penalty < minpenalty) 
                {
                    best_hour = i+1;
                    minpenalty = penalty; 
                }
            }
            else penalty++;
        }
    return best_hour;
    }
};