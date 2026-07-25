// https://leetcode.com/problems/minimum-operations-to-sort-a-string

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin() , s.end())) return 0;

        if(n < 3) return -1;

        char mini = *min_element(s.begin() , s.end());
        char maxi = *max_element(s.begin() , s.end());

        if(s.front() == mini or s.back() == maxi) return 1;
        if(s.front() == maxi and s.back() == mini and count(s.begin() , s.end() , maxi) == 1 and count(s.begin() , s.end() , mini) == 1) return 3;
                                                                                                            return 2;
    }
};