// https://leetcode.com/problems/finding-3-digit-even-numbers

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        set<int>st;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                for(int k = 0 ; k < n ; k++)
                {
                    if(i != j and i != k and j != k && digits[i] != 0 && digits[k] % 2 == 0)
                    {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if(num % 2 == 0)
                        {
                            st.insert(num);
                        }
                    }
                }
            }
        }

        for(auto it : st) ans.push_back(it);
        return ans;
    }
};