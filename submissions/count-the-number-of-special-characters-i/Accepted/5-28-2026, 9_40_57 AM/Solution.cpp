// https://leetcode.com/problems/count-the-number-of-special-characters-i

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st;

        for(auto it : word) st.insert(it);

        int count = 0;
        for(auto it : word)
        {
            if(it >= 'A' and it <= 'Z') continue;
            else if(st.count(toupper(it))) 
            {
                count++;
                st.erase(toupper(it));
            }
        }
        return count;
    }
};