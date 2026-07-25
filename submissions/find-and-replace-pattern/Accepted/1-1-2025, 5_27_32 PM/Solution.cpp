// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    void normalise(string &s){
        char start = 'a';
        unordered_map<char,char> mapping;
        for(int i=0; i<s.length();i++){
            if(mapping.find(s[i]) == mapping.end()){
                mapping[s[i]] = start;
                start ++;
            }
        }
        for(int i=0; i<s.length();i++){
                s[i] = mapping[s[i]];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        normalise(pattern);
        vector<string>ans;
        
        for(int i=0; i<words.size(); i++){
            string currword = words[i];
            string wordcopy = currword;

            normalise(wordcopy);
            if(wordcopy.compare(pattern) ==0){
                ans.push_back(currword);
            }
        }
        return ans;
    }
};