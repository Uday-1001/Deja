// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<pair<char , int>>radiant;
        deque<pair<char , int>>dire;

        int n = senate.size();

        //pushing all the members with indexes in their parties.
        for(int i=0 ; i<senate.size() ; i++)
        {
            char member = senate[i];

            if(member == 'R') 
                radiant.push_back({'R' , i});
            else
                dire.push_back({'D' , i});
        }

        while(!radiant.empty() && !dire.empty())
        {
            auto r = radiant.front();
            auto d = dire.front();

            radiant.pop_front();
            dire.pop_front();

            if(r.second > d.second)
            {
                //means that dire will ban the radiant person
                dire.push_back({'D' , d.second + n});
            }
            else
            {
                radiant.push_back({'R' , r.second + n});
            }
        }
        //if any of the queue is empty , it comes here for answer generation
    return (!radiant.empty()) ? "Radiant" : "Dire";
    }
};