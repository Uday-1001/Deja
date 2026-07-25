// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
       int partKaindex = s.find(part);
       
       while(partKaindex != -1){

            s.erase(partKaindex , part.length());
       }

       return s;

    }
};