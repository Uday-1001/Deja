// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int pattern_zero = 0, pattern_one = 0;

        for(int i = 0; i < n; i++) 
        {
            if(i % 2 == 0) 
            {
                if(s[i] != '0') pattern_zero++;  
                if(s[i] != '1') pattern_one++;   
            }
            else 
            {
                if(s[i] != '1') pattern_zero++;
                if(s[i] != '0') pattern_one++;
            }
        }
        cout<<pattern_zero << " "<<pattern_one<<endl;
        return min(pattern_zero, pattern_one);
    }
};