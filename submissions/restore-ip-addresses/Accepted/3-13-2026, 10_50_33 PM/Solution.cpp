// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:
    vector<string>strings;

    bool isValid(string &s)
    {
        if(s.size() > 1 and s[0] == '0') return false;
        
        int num = stoi(s);
        return num >= 0 and num <= 255;
    }
    
    void byrec(string &s , int parts , string formed , int i)
    {
        //base case 
        if(i == s.size() and parts == 4) 
        {
            formed.pop_back();
            strings.push_back(formed);
            return;
        }
        
        if(s.size() < 4 or s.size() > 12) return;
        
        if(parts == 4) return;
        
        //ek case hum solve karenge
        for(int len = 1 ; len <= 3; len++)
        {
            if(i + len > s.size()) break;
            
            string str_num = s.substr(i , len);
            
            if(isValid(str_num))
            {
                string new_s = str_num + ".";
                byrec(s , parts + 1 , formed + new_s , i + len);
            }
        }   
    }

    vector<string> restoreIpAddresses(string s) {
        byrec(s , 0 , "" , 0);
        return strings;
    }
};