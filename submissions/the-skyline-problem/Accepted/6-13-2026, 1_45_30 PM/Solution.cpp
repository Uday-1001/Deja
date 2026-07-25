// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:
    using pi = pair<int,int>;

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>ans;

        vector<pi>vp;
        for(auto it : buildings)
        {
            int st = it[0];
            int end = it[1];
            int ht = it[2];

            vp.push_back({st , +ht});
            vp.push_back({end , -ht});
        }

        sort(begin(vp) , end(vp) , [](const pair<int,int>&a , const pair<int,int>&b){
            if(a.first == b.first) return b.second < a.second;
            return a.first < b.first;
        });

        multiset<int>st;
        st.insert(0);

        int prevmaxht = 0;

        for(auto it : vp)
        {
            auto[pt , ht] = it;
            if(ht < 0)
            {
                auto iterator = st.find(abs(ht));
                if(iterator != st.end()) st.erase(iterator);
            }
            else st.insert(ht);

            int maxht = *st.rbegin();

            if(maxht != prevmaxht) 
            {
                ans.push_back({pt , maxht});
                prevmaxht = maxht;
            }
        }
        return ans;
    }
};