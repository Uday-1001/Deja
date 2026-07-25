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

        while(head && st.count(head->val))
        {
            ListNode* temp = head;
            head = head->next;
        }

        if(!head) return nullptr;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr)
        {
            if(st.count(curr->val))
            {
                ListNode* temp = curr;
                curr = curr->next;
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    return head;
    }
};