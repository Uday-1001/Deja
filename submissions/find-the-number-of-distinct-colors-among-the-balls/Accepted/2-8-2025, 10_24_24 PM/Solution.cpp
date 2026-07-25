// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>balls_map;
        unordered_map<int,int> colour;
        vector<int>ans;

        for(auto  mark : queries)
        {
            int ball = mark[0];
            int color = mark[1];

            if(balls_map.find(ball) == balls_map.end())
            {
                balls_map[ball] = color;

                int old_color = balls_map[ball];
                colour[old_color]++;  
            }
            else
            {
                colour[balls_map[ball]]--;

                if(colour[balls_map[ball]]==0)
                colour.erase(balls_map[ball]);

                balls_map[ball] = color;
                colour[color]++;
            }
            
            ans.push_back(colour.size());
        }
    return ans;
    }
};