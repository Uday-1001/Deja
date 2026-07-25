// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i

class Solution {
public:
    long long sumAndMultiply(int n) {
        string ans = "";
        string s = to_string(n);
        long long sum = 0;
        for(auto ch : s){
            if(ch != '0'){
                ans.push_back(ch);
                sum += ch - '0';
            } 
        }
        long long new_n = stol(ans);
        long long new_sum = new_n * sum;
        return new_sum;
    }
};