// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    using pi = pair<int,int>;
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        set<pi>st;

        for(int i = 0 ; i<arr.size() ; i++)
        {
            int bits = 0;
            int num = arr[i];
            while(num > 0)
            {
                bits += (num & 1) ? 1 : 0;
                num >>= 1;
            }
            st.insert({bits , arr[i]});
        }

        for(auto it : st) ans.push_back(it.second);
        return ans;
    }
};