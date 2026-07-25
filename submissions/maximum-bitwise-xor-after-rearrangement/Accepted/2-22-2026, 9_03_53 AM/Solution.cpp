// https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement

class Solution {
public:
    string maximumXor(string s, string t) {
        int ones = 0;
        int zeros = 0;

        for(auto it : t){
            if(it == '1') ones++;
            else zeros++;
        } 

        string formation = "";
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '0')
            {
                if(ones > 0) 
                {
                    formation.push_back(1 + '0');
                    ones--;
                }
                else 
                {
                    formation.push_back(0 + '0');
                    zeros--;
                }
            }
            else 
            {
                if(zeros > 0) 
                {
                    formation.push_back(0 + '0');
                    zeros--;
                }
                else
                {
                    formation.push_back(1 + '0');
                    ones--;
                }
            }
        }
    string ans = "";
        for(int i = 0 ; i<formation.size() ; i++){
            if(s[i] == formation[i]) ans.push_back('0');
            else ans.push_back('1');
        }
    return ans;
        
    
    }
};