// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string ans = "";
    int index = 0;
    
    string customSortString(string order, string s) {
        for(int i = 0 ;i <order.size() ; i++)
        {
            for(int j = i ; j<s.size() ; j++)
            {
                if(s[j] == order[i])
                {
                    swap(s[j] , s[index]);
                    index++;
                }
            }
        }
    return s;
    }
};