// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        map<int,int> mp;
        vector<int> ans;
        int count = 0;

        for(auto &q : queries){
            int index = q[0];
            int color = q[1];

            if(mp.count(index)){
                int old = mp[index];

                if(mp.count(index-1) && mp[index-1] == old) count--;
                if(mp.count(index+1) && mp[index+1] == old) count--;
            }

            mp[index] = color;

            if(mp.count(index-1) && mp[index-1] == color) count++;
            if(mp.count(index+1) && mp[index+1] == color) count++;

            ans.push_back(count);
        }

        return ans;
    }
};