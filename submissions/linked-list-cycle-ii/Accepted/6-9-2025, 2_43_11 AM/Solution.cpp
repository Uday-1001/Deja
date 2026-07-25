// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int>mpp;

        ListNode* temp = head;

        while(temp != nullptr)
        {
            if(mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            mpp[temp]++;
            temp = temp->next;
        }
    return nullptr;
    }
};