// https://leetcode.com/problems/reorder-list

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
        ListNode* curr;

//APPROACH 2

    void solve(ListNode* head)
    {
        //base case 
        if(head == NULL) return;

        solve(head->next);

        ListNode* temp = curr->next;

        if(curr->next == NULL) return;

        else if(curr == head)
        {
            curr->next = NULL;
            return;
        }

        curr->next = head;
        head ->next = (temp == head) ? NULL : temp;
        curr = temp;
    }

    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};