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
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
    return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = getsize(head);
        vector<ListNode*>ans(k , nullptr);

        int partition_size = size / k;
        int extra_nodes = size % k;

        ListNode* it = head;
        for(int i=0 ; i<k && it ; i++)
        {
            ans[i] = it;
            int curr_part_size = partition_size + (extra_nodes > 0 ? 1 : 0);
            extra_nodes--;

                for(int j = 0; j<curr_part_size-1 ; j++)
                {
                    it = it->next;
                }
            
            ListNode* next_partition_start = it->next;
            it->next = nullptr;
            it = next_partition_start;
        }
    return ans;
    }
};