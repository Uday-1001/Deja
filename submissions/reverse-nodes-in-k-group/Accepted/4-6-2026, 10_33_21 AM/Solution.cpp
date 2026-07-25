// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    int getlen(ListNode* root)
    {
        int len = 0;
        ListNode* temp = root;
        while(temp != nullptr)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* byrec(ListNode* head , int k)
    {
        int len = getlen(head);
        if(!head or !head->next or len < k) return head;
        
        int pos = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(pos < k)
        {
            ListNode* frontnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frontnode;
            pos++;
        }

        ListNode* endnode = byrec(curr , k);
        head->next = endnode;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return byrec(head , k);
    }
};