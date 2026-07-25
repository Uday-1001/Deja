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
    int getlen(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getlen(head);
        if(len < k or !head or !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        int req = k;

        for(int i = 0 ; i<req ; i++) 
        {
            auto frontnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frontnode;
        }

        auto reversedhead = reverseKGroup(curr , k);
        head->next = reversedhead;

        return prev;
    }
};