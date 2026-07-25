// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = head->next;

        while(even != NULL && even->next != NULL)
        {
           odd->next = odd->next->next;
           even->next = even->next->next;
           
           //moving the pointers after link change
           odd = odd->next;
           even = even->next;
        }
        //attach odd to evenhead
        odd->next = evenhead;
    return head;
    }
};