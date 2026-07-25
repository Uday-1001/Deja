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

    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr)
        {
            auto frontnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frontnode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        int len = getlen(head);
        if(len == 1) return true;

        ListNode* curr = head;
        int mid = len / 2;

        for(int i = 0 ; i<mid ; i++) curr = curr->next;

        ListNode* atmiddle;
        if(len & 1) atmiddle = reverseLL(curr->next);
        else atmiddle = reverseLL(curr);

        ListNode* temp = head;

        for(int i = 0 ; i<mid ; i++)
        {
            if(temp->val != atmiddle->val) return false;
            else
            {
                temp = temp->next;
                atmiddle = atmiddle->next;
            }
        }
        return true;
    }
};