// https://leetcode.com/problems/split-linked-list-in-parts

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
    int getsize(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
    return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getsize(head);
        int part_size = n/k;
        int extras = n%k;
        ListNode* it = head;

        vector<ListNode*>ans(k , nullptr);

        for(int i=0 ; i < k && it ; i++)
        {
            ans[i] = it;
            int curr_partsize = part_size + (extras > 0 ? 1 : 0);
            extras--;
            for(int j =0 ; j<curr_partsize-1 ; j++)
            {
                it = it->next;
            }

            ListNode* next_partstart = it->next;
            it->next = NULL;
            it = next_partstart;   
        }
    return ans;
    }
};