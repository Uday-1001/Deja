// https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes

class Solution {
public:
    using ll = long long;
    
    vector<int> findGoodIntegers(int n) {
        vector<int>sum;

        for(ll a = 1 ; a*a*a <= n ; a++){
            for(ll b = a ; (a*a*a + b*b*b) <= n ; b++){
                sum.push_back(a*a*a + b*b*b);
            }
        }

        sort(begin(sum) , end(sum));
        vector<int>ans;
        for(int i = 1 ; i<sum.size() ; i++){
            if(sum[i] == sum[i-1])
            {
                if(ans.empty() or ans.back() != sum[i]) ans.push_back(sum[i]);
            }
        }
        return ans;
    }
};