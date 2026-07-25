// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(digit);
            temp = temp->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* finalans = ans->next;
        delete(ans);
        return finalans;
    }
};