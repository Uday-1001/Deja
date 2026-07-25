// https://leetcode.com/problems/palindrome-linked-list

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
    ListNode* reverseList(ListNode* head) 
    {
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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //yha pr slow first middle node pe hoga
        ListNode* newhead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;

        while(second != NULL)
        {
            if(first->val != second->val)
            return false;
            else
            {
                first = first->next;
                second = second->next;
            }
        }
        reverseList(newhead);
        return true;
    }
};