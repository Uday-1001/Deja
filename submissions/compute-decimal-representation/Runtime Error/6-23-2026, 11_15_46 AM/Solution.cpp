// https://leetcode.com/problems/compute-decimal-representation

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;

        int placeofdigit = 1;
        while(n > 0)
        {
            int digit = n % 10;
            if(placeofdigit * digit != 0) ans.push_back(placeofdigit * digit);
            placeofdigit *= 10;
            n /= 10;
        }
        reverse(begin(ans) , end(ans));
        return ans;
    }
};