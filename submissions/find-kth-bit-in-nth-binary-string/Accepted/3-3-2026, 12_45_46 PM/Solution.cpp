// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string

class Solution {
public:
    string getTail(string &head)
    {
        string tail = "";
        for(int i = head.size()-1 ; i >= 0 ; i--)
        {
            tail += (head[i] == '0') ? '1' : '0';
        }
    return tail;
    }

    string byrec(int n)
    {
        if(n == 1) return "0";

        string head = byrec(n-1);
        string mid = "1";

        string tail = getTail(head);

        return head + mid + tail;
    }

    char findKthBit(int n, int k) {
        string ans = byrec(n);
        return ans[k-1];
    }
};