// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balls_map;
        
        vector<int>ans;

        for(int i=0 ; i<queries.size() ; i++)
        {
            int ball = queries[i][0];
            int colour = queries[i][1];

            balls_map[ball] = colour;
            
            unordered_set<int> unique_colours;
            for(auto it : balls_map)
            {
                unique_colours.insert(it.second);
            }
            ans.push_back(unique_colours.size());
        }
    return ans;   
    }
};