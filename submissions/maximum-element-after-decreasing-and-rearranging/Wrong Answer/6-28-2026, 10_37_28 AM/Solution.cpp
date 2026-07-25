// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        unordered_set<int>st(begin(arr) , end(arr));

        int ans = 1;
        if(st.count(1)) 
        {
            int nextelem = 2;
            while(st.count(nextelem))
            {
                ans++;
                nextelem++;
            } 
            return (ans == 1) ? arr.size() : ans;
        }
        else return *st.begin();
    }
};