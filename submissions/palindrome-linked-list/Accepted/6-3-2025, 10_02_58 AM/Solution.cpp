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
    bool isPalindrome(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;

            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        //yha or ab slow middle node pr khada hua hai aur peeche tak sab reversed hai 
        if(fast != NULL)
        {
            slow = slow->next;
        }

        while(slow != NULL && prev != NULL)
        {
            if(slow->val != prev->val)
            {
                return false;
            }
            else
            {
                slow = slow->next;
                prev = prev->next;
            }
        }
    return true;
    }
};