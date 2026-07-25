// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char>even(26 , 0);
        vector<char>odd(26 , 0);

        for(int i=0; i<s1.size(); i++)
        {
            if(i%2 == 0)
            {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
            else
            {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0 ; i<s1.size() ; i++) if(even[i] or odd[i]) return false;
        return true;
    } 
};