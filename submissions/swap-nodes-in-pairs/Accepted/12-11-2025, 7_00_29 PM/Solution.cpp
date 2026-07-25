// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* byrec(ListNode* head)
    {
        if(!head or head->next == nullptr) return head;

        ListNode* temp = head;
        ListNode* tail = temp->next;

        ListNode* tailnext = tail->next;
        tail->next = temp;
        temp->next = byrec(tailnext);

        return tail;
    }
    ListNode* swapPairs(ListNode* head) {
        return byrec(head);
    }
};