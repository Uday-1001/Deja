// https://leetcode.com/problems/reverse-nodes-in-k-group

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
        int len =0;

        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
    return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getlen(head);

        //base cases 
        if(head == NULL || head->next == NULL) return head;
        
        if(len < k ) return head;

        //ek case hum solve karenge baaki ka recursion dekhlega
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(k-- && curr->next != NULL)
        {
            ListNode* front = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = front;
        }
        
        if(curr != NULL)
        {
            ListNode* recursionhead = reverseKGroup(curr , k);
            head->next = recursionhead;
        }
    return prev;
    }
};