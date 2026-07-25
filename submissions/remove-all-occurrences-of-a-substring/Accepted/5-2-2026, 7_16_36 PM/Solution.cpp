// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string str = "";
        int partsize = part.size();

        for(int i = 0 ; i<s.size() ; i++)
        {
            str.push_back(s[i]);

            if(str.size() >= partsize)
            {
                if(str.substr(str.size() - partsize) == part)
                {
                    int size = partsize;
                    while(size--) str.pop_back();
                }    
            }
        }
        return str;
    }
};