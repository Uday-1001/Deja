// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummylesser = new ListNode(0);
        ListNode* dummygreater = new ListNode(0);

        auto prevlesser = dummylesser;
        auto prevgreater = dummygreater;
        auto curr = head;

        while(curr)
        {
            if(curr->val < x) 
            {
                prevlesser->next = curr;
                prevlesser = curr;
            }
            else 
            {
                prevgreater->next = curr;
                prevgreater = curr;
            }
            curr = curr->next;
        }
        prevgreater->next = nullptr;
        prevlesser->next = dummygreater->next;

        return dummylesser->next;
    }
};