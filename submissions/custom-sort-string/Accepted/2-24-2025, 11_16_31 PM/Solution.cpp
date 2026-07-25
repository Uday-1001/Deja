// https://leetcode.com/problems/custom-sort-string

string ord;
class Solution {
public:

    static bool comp(char a ,char b)
    {
        if(ord.find(a) < ord.find(b)){
            return true;
        }
        return false;
    }
    string customSortString(string order, string s) {
        ord = order;
        sort(s.begin()  ,s.end() , comp);
        return s;
    }
};
