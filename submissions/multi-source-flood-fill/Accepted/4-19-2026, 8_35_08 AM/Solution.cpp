// https://leetcode.com/problems/multi-source-flood-fill

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>ans(n , vector<int>(m , 0));
        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        
        queue<pair<int,int>>q;
        for(int i = 0 ; i<sources.size() ; i++){
            int r = sources[i][0];
            int c = sources[i][1];
            int color = sources[i][2];
            ans[r][c] = color;
            dist[r][c] = 0;
            q.push({r,c});
        }

        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        while(!q.empty()){
            auto [r , c] = q.front();
            q.pop();

            int curr_color = ans[r][c];
            int curr_dist = dist[r][c];
            
            for(int k = 0 ; k<4 ; k++){
                int newr = r + dr[k];
                int newc = c + dc[k];

                if(newr < n and newr >= 0 and newc < m and newc >= 0){
                    if(curr_dist + 1 < dist[newr][newc]){
                        ans[newr][newc] = curr_color;
                        dist[newr][newc] = dist[r][c] + 1;
                        q.push({newr , newc});
                    }
                    else if(curr_dist + 1 == dist[newr][newc]){
                        ans[newr][newc] = max(curr_color , ans[newr][newc]);
                    }
                }
            }
        }
    return ans;
    }
};