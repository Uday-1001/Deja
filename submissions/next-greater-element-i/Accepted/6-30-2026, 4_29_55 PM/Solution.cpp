// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>ans(n1);
        unordered_map<int,int>mp;

        stack<int>st;
        st.push(-1);

        for(int i = nums2.size()-1 ; i>=0 ; i--)
        {
            while(st.top() != -1 and nums2[st.top()] <= nums2[i])
            {
                st.pop();
            }
            
            if(st.top() == -1) mp[nums2[i]] = -1;
            else mp[nums2[i]] = nums2[st.top()];

            st.push(i);
        }

        for(int i = 0 ; i<nums1.size() ; i++) ans[i] = mp[nums1[i]];
        return ans;
    }
};