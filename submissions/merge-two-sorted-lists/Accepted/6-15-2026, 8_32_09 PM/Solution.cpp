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
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* temp = new ListNode(-1);

        ListNode* dummy = temp;

        while(p1 != nullptr and p2 != nullptr)
        {
            if(p1->val >= p2->val)
            {
                dummy->next = p2;
                p2 = p2->next;
            }
            else
            {
                dummy->next = p1;
                p1 = p1->next;
            }
            dummy = dummy->next;
        }

        while(p1 != nullptr)
        {
            dummy->next = p1;
            p1 = p1->next;
            dummy = dummy->next;
        }
        while(p2 != nullptr)
        {
            dummy->next = p2;
            p2 = p2->next;
            dummy = dummy->next;
        }

        return temp->next;
    }
};