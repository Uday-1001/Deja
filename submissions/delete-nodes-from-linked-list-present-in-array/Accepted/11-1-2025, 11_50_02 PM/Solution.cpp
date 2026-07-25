// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto num : nums) st.insert(num);

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while(curr->next)
        {
            if(st.find(curr->next->val) != st.end())
            {
                curr->next = curr->next->next;
            }
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};