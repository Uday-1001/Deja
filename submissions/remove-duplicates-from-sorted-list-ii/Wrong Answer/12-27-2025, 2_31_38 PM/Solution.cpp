// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* curr = head;

        while(curr)
        {
            bool isduplicate = false;
            while(curr && curr->next && (curr->val == curr->next->val))
            {
                curr = curr->next;
                isduplicate = true;
            }
            if(!isduplicate)
            {
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};