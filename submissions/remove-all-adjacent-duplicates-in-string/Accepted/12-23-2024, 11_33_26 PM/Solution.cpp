// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i=0 ; i<s.length(); i++){
            char current = s[i];
            if(ans.empty()){
                ans.push_back(current) ;
            }
            else if(current == ans.back()){
                ans.pop_back();
            }
            else if(current != ans.back()){
                ans.push_back(current);
            }  
        }
        return ans;
        
    }
};