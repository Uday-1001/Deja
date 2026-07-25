// https://leetcode.com/problems/rotate-list

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
        ListNode* temp = root;
        int len = 0;
        while(temp != nullptr)
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

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int len = getlen(head);
        k %= len;

        if(k == 0) return head;

        ListNode* curr = head;
        for(int i = 0 ; i<(len - k - 1) ; i++) curr = curr->next;

        auto nextpointer = curr->next;
        ListNode* temp = nextpointer;
        curr->next = nullptr;
        while(nextpointer->next) nextpointer = nextpointer->next;

        nextpointer->next = head;
        return temp;
    }
};