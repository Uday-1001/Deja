// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<pair<char , int>>radiant;
        queue<pair<char , int>>dire;

        //pushing all the members with indexes in their parties.
        for(int i=0 ; i<senate.size() ; i++)
        {
            char member = senate[i];

            if(member == 'R') 
                radiant.push({'R' , i});
            else
                dire.push({'D' , i});
        }

        int index = 0;
        while(!radiant.empty() && !dire.empty() && index < senate.size())
        {
            char banning_person = senate[index];

            if(banning_person == 'R')
            {
                int last_index = radiant.back().second;
                radiant.pop();
                dire.pop();
                radiant.push({banning_person , (last_index + 1)});
            }
            else
            {
                int last_index = radiant.back().second;
                dire.pop();
                radiant.pop();
                dire.push({banning_person , (last_index + 1)});
            }

            index ++;
        }
        //if any of the queue is empty , it comes here for answer generation
    return (!radiant.empty()) ? "Radiant" : "Dire";
    }
};