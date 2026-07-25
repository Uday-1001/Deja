// https://leetcode.com/problems/custom-sort-string

string ordercopy;
class Solution {
public:
    static bool comp(char a , char b)
    {
        return(ordercopy.find(a) < ordercopy.find(b));
    }
    string customSortString(string order, string s) {
        ordercopy = order;
        sort(s.begin() , s.end() , comp);
        return s;
    }
};