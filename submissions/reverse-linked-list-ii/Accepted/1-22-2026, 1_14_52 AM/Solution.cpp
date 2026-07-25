// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* ptl = dummy;
        ListNode* rightNode = dummy;

        //getting the ptl and ntr pointers at right place 
        for(int i = 0 ; i<left-1 ; i++) ptl = ptl->next;

        for(int i = 0 ; i<right ; i++) rightNode = rightNode->next;

        ListNode* leftptr = ptl->next;
        ListNode* ntr = rightNode->next;

        ListNode* curr = leftptr;
        ListNode* prev = nullptr;

        // done the reversal of the left to right nodes here
        int pos = right - left + 1;
        while(pos--)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        //reconnecting the pointers in the list
        ptl->next = prev;
        leftptr->next = ntr;

        return dummy->next;
    }
};