// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;

        while(node->next != nullptr)
        {
            auto nextnodeval = node->next->val;
            node->val = nextnodeval;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        
        delete(node);
    }
};