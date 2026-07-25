// https://leetcode.com/problems/count-distinct-integers-after-removing-zeros

class Solution {
public:
    long long remove_zeros(string s)
    {
        string ans = "";
        int num = 0;
        for(auto ch : s){
            if(ch == '0') continue;
            ans.push_back(ch);
        }
        num = stoi(ans);
        return num;
    }
    
    long long countDistinct(long long n) {
        set<long long>st;
        for(int i=1 ; i<=n ; i++){
            string num = to_string(i);
            int ans = remove_zeros(num);

            st.insert(ans);
        }
        return st.size();
    }
};