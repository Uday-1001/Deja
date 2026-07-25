// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast->next != NULL)
            {
                slow = slow->next;
            }

            if(fast == slow && fast->next  != NULL)
            {
                return fast->next->next;
            }
        }
    return nullptr;
    }
};