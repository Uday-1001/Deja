// https://leetcode.com/problems/middle-of-the-linked-list

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

        while(temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int len = getlen(head);
        ListNode* curr = head;

        int mid = len / 2;
        for(int i = 0 ; i<mid ; i++) curr = curr->next;

        return curr;
    }
};