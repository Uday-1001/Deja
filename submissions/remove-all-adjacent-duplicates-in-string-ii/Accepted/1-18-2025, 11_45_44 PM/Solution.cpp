// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        // The Two pointer approach :- Slipping i

        int i =0;
        int j =0;
        
        vector<int> count(s.size());
        while(j < s.size())
        {
            s[i] = s[j];
            count[i] = 1;

            if(i>0 && s[i] == s[i-1])
            count[i] += count[i-1];

            if(count[i] == k)
            i = i-k;
             
            i++; j++;
        }
    return(s.substr(0,i));
    }
};