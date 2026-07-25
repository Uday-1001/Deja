// https://leetcode.com/problems/next-greater-node-in-linked-list

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
        ListNode* temp = head;
        int count =0;
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
    return count;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        int len = getlen(head);

        //stores the indexes
        stack<int>st;

        vector<int>llarray;
        vector<int>ans(len , 0);

        //made the linled list vector for comparison in stack
        ListNode* temp = head;
        while(temp != nullptr)
        {
            llarray.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=0 ; i<len ; i++)
        {
            while(!st.empty() && llarray[st.top()] < llarray[i])
            {
                //means that the top of the stack has the index whose element is smaller than the current element
                int chota = st.top();
                st.pop();
                ans[chota] = llarray[i];
            }
            //push to har baar he krna hai
                st.push(i);
        }
    return ans;    
    }
};