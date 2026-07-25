// https://leetcode.com/problems/sort-list

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

    ListNode* mergerfxn(ListNode* l1 , ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        //any remaining elements if not encountered yet
        if(l1 != NULL)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
    return dummy->next;
    }

    ListNode* findmiddle(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* middle = findmiddle(head);

        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergerfxn(left , right);
    }
};