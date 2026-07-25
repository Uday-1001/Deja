// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    void recursion(string&s , string &part)
    {
        //base case
        int indexOfpart = s.find(part);
        if(indexOfpart == string::npos)
        {
            return;
        }
        //ek case hum solve krenge aur baaki recursion dekh lega
        string left_part = s.substr(0,indexOfpart);
        string right_part = s.substr(indexOfpart + part.size() , s.size());

        s = left_part + right_part;

        recursion(s , part);
        
    }

    string removeOccurrences(string s, string part) {
        recursion(s, part);
        return s;
    }
};