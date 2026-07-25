// https://leetcode.com/problems/fair-candy-swap

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int>answer(2);
        set<int>st;
        for(auto &a : bobSizes)
        {
            st.insert(a);
        }
        
        int alice = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int bob = accumulate(bobSizes.begin(),bobSizes.end(),0);
        int diff_candies = (alice - bob)/2;

        for(auto &x : aliceSizes)
        {
            if(st.find(x - diff_candies) != st.end())
            {
                answer[0] = x;
                answer[1] = (x - diff_candies);
            }
        }
        return answer;
    }
};