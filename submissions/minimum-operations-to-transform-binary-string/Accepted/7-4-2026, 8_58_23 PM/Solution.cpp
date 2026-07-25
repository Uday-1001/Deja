// https://leetcode.com/problems/minimum-operations-to-transform-binary-string

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int cost = 0;

        for(int i = 0 ; i<n ; i++){
            if(s1[i] == s2[i]) continue;
            if(s2[i] == '1'){
                s1[i] = '1';
                cost++;
            }
            else if(s2[i] == '0')
            {
                if(i+1 < n and s1[i+1] == '1'){
                    cost += (s1[i] == '1') ? 1 : 2;
                    s1[i] = '0';
                    s1[i+1] = '0';
                }
                else if(i+1 < n){
                    cost += 2;
                    s1[i] = '0';
                    s1[i+1] = '0';
                }
                else if(i-1 >= 0){
                    cost += 2;
                    s1[i] = '0';
                    s1[i-1] = s2[i-1];
                }
                else return -1;
            }
        }
        return cost;
    }
};