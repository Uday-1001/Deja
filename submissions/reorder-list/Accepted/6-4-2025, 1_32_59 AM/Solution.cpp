// https://leetcode.com/problems/reorder-list

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

//APPROACH 1

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* newnode = reverseList(head->next);

        ListNode* forward = head->next;
        forward->next = head;
        head->next = NULL;
        return newnode;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;    

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reached the middle node with the slow pointer 
        ListNode* revhead = reverseList(slow);

        ListNode* curr = head;

        while(revhead->next != NULL)
        {
            ListNode* temp = curr->next;
            ListNode* temprev = revhead->next;

            curr->next = revhead;
            revhead->next = temp;
            curr = temp;
            revhead = temprev;
        }
    }
};