// https://leetcode.com/problems/find-the-most-common-response

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& response) {
        map<string , int>mp;
        string ans = "";

        for(int i = 0 ; i<response.size() ; i++)
        {
            set<string>st;
            for(int j = 0; j<response[i].size() ; j++)
            {
                st.insert(response[i][j]);
            }
            for(auto it : st) mp[it]++;
        }
        int max_freq = 0;
        for(auto it : mp)
        {
            if(it.second > max_freq)
            {
                max_freq = it.second;
                ans = it.first;
            } 
        }

       return ans;
    }
};