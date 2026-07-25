// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string &order, string &s) {
        for(int i = 0; i<order.length(); i++){
            for(int j = i; j<s.length(); j++){
                if(s[j] == order[i]){
                    swap(s[j], s[i]);
                }
            }
        }
        return s;
    }
};