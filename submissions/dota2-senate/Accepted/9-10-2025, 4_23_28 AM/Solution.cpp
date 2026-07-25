// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<pair<char , int>>radiant;
        queue<pair<char , int>>dire;

        int n = senate.size();

        //pushing all the members with indexes in their parties.
        for(int i=0 ; i<senate.size() ; i++)
        {
            char member = senate[i];

            if(member == 'R') 
                radiant.push({'R' , i});
            else
                dire.push({'D' , i});
        }

        while(!radiant.empty() && !dire.empty())
        {
            auto r = radiant.front();
            auto d = dire.front();

            radiant.pop();
            dire.pop();

            if(r.second > d.second)
            {
                //means that dire will ban the radiant person
                dire.push({'D' , d.second + n});
            }
            else
            {
                radiant.push({'R' , r.second + n});
            }
        }
        //if any of the queue is empty , it comes here for answer generation
    return (!radiant.empty()) ? "Radiant" : "Dire";
    }
};