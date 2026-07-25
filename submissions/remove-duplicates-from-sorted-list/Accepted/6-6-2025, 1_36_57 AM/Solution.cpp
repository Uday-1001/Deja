// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp != NULL)
        {
            if(prev->val == temp->val)
            {
                prev->next = temp->next;
                temp->next = NULL;
                delete(temp);
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
            temp = prev->next;
        }
    return head;
    }
};