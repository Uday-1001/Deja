// https://leetcode.com/problems/remove-nodes-from-linked-list

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        ListNode* newhead = new ListNode(prev->val);

        int maxi = newhead->val;
        //reinitailize the curr to the next node of the prev 
        curr = prev->next;

        while(curr != NULL)
        {
            if(curr->val >= maxi)
            {
                ListNode* newnode = new ListNode(curr->val);
                newnode->next = newhead;
                newhead = newnode;
                maxi = newhead->val;
            }
            curr = curr->next;
        }
    return newhead;
    }
};