// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverselist(ListNode* &prev , ListNode* &curr)
    {
        if(curr == NULL)
        {
            //iska matlab list reverse ho chuki hai 
            return prev;
        }
        //ek case hum solve karenge baaki ka recursion dekhlega
        ListNode* forward = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = forward;

        return reverselist(prev , curr);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        ListNode* newhead = reverselist(prev , curr);
        return newhead;
    }
};