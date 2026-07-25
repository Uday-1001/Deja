// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapping;
        bool isTmapped  = false ;
        for(int i=0;i<s.size();i++){
            char start = s[i];
            if(mapping.find(start) != mapping.end()){
               isTmapped = false;
            }
            else
            {
                mapping[start] = t[i];
                isTmapped = true;
            }
        }
        for(int i =0; i<s.size();i++){
            if(char(mapping[s[i]]) != t[i] && isTmapped == false){
                return false;
            }  
        }
        return true;
    }
};