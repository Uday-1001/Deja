// https://leetcode.com/problems/remove-nodes-from-linked-list

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
    ListNode* removeNodes(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        //ITERATIVE APPROACH FOR LIST REVERSAL
        while(curr != NULL)
        {
            ListNode* forward = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        ListNode* newhead = new ListNode(prev->val);
        
        int maxi = newhead->val;
        curr = prev->next;

        while(curr != NULL)
        {
            if(curr->val >= maxi)
            {
                //insert the big mode
                ListNode* node = new ListNode(curr->val);
                node->next = newhead;
                newhead = node;
                maxi = node->val;
            }
            //varna ye condition to har baar he lagegi
            curr = curr ->next;
        }
        return newhead;
    } 
};