// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
        int length = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
    return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getlen(head);
        int nodetodelete = length - n + 1;

        //if you have to delete the first node
        if(nodetodelete == 1)
        {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else if(nodetodelete == length)
        {
            ListNode* temp = head;
            for(int i= 0 ; i<nodetodelete - 2 ; i++)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        else
        {
            ListNode* temp = head;
            for(int i= 0 ; i<nodetodelete - 2 ; i++)
            {
                temp = temp->next;
            }
            ListNode* curr = temp->next;
            ListNode* forward = curr->next;
            temp->next = forward;
            curr->next = NULL;
        }
    return head;
    }
};