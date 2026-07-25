// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    int getlen(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL)
        {
            temp = temp->next;
            len++;
        }
    return len;
    }

    ListNode* deleteMiddle(ListNode* head) {
        int position = (getlen(head)) / 2 + 1;
        ListNode* temp = head;

        for(int i=0; i<position-2 ; i++)
        {
            temp = temp->next;
        }
        ListNode* curr = temp->next;
        ListNode* forward = curr->next;

        temp->next = forward;
        curr->next = NULL;
        delete(curr);
        return head;
    }
};