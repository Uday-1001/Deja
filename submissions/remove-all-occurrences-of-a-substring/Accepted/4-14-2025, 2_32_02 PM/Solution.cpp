// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    void removeoccurence(string &s  ,string &part){
        int starting_index = s.find(part);

        if(starting_index != string::npos)
        {
            string left_part = s.substr(0,starting_index);
            string right_part = s.substr(starting_index + part.size() , s.size());
            s = left_part + right_part;

            removeoccurence(s,part);
        }
        else
        {
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeoccurence(s,part);
        return s;
    }
};