// https://leetcode.com/problems/next-greater-node-in-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //ALTERNATE APPROACH

    vector<int> nextLargerNodes(ListNode* head) {
        //stores pair of {index , val} pairs in it 
        stack<pair<int,int>>st;

        vector<int>ans;

        //keeps track of the index of the linked list nodes
        int i=0;

        while(head != nullptr)
        {
            ans.push_back(0);

            //check if the value in the pair is lesser than that of the current element
            while(!st.empty() && (st.top().second < head->val))
            {
                auto chota_index = st.top();
                st.pop();
                ans[chota_index.first] = head->val;
            }
            //push the elements 
            st.push({i++ , head->val});
            head = head->next;
        }
        return ans;
    }
};