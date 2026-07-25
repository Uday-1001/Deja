// https://leetcode.com/problems/merge-adjacent-equal-elements

class Solution {
public:
    using ll = long long;
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<ll>st;

        for(int i=0 ; i<nums.size() ; i++){
            ll curr = nums[i];
            while(!st.empty() and st.top() == curr){
                curr += st.top();
                st.pop();
            }
            st.push(curr);
        }
        vector<ll>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};