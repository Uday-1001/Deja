// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string num = "";
        for(auto it : digits){
            num.push_back(it + '0');
        }
        int n = stoi(num);
        n++;
        vector<int>ans;
        while(n > 0){
            int digit = n % 10;
            ans.push_back(digit);
            n /= 10;
        }
        reverse(begin(ans) , end(ans));
        return ans;
    }
};