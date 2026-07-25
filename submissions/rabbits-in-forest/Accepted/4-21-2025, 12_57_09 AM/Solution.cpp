// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int total_count = 0;

        for(auto ans : answers)
        {
           if(mp[ans] == 0)
            {
                total_count += ans + 1;
                mp[ans] = ans;
            } 
           else
            {
                mp[ans] --;
            }
        }
    return total_count;
    }
};