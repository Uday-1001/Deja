// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string &order, string &s) {
        int index = 0;
        for(int i = 0; i<order.length(); i++){
            for(int j = i; j<s.length(); j++){
                if(s[j] == order[i]){
                    swap(s[j], s[index]);
                    index++;
                }
            }
        }
        return s;
    }
};