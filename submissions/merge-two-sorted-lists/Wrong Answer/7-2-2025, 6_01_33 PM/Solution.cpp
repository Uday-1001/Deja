// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* it1 = list1;
        ListNode* it2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(it1 && it2)
        {
            if(it1->val <= it2->val)
            {
                temp->next = it1;
                it1 = it1->next;
            }
            else
            {
                temp->next = it2;
                it2 = it2->next;
            }
            temp = temp->next;
        }
        while(it1)
        {
            temp->next = it1;
            it1 = it1->next;
        }
        while(it2)
        {
            temp->next = it2;
            it2 = it2->next;
        }
    return dummy->next;
    }
};