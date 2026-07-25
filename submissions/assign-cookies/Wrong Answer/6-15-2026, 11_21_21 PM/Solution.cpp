// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g) , end(g));
        sort(begin(s) , end(s));

        int count{};
        int i{} , j{};

        while(i < s.size() and j < g.size())
        {
            if(s[i] >= g[j]) count++;
            i++;
            j++;
        }
        return count;
    }
};