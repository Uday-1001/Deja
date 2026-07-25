// https://leetcode.com/problems/count-distinct-integers-after-removing-zeros

class Solution {
public:
    long long countDistinct(long long n) {
        set<long long>st;
        for(int i =1; i <=n ; i++){
            if(i % 10 == 0) continue;
            else
            {
                string num = to_string(i);
                int hasZero = false;
                for(auto ch : num){
                    if(ch == '0') hasZero = true;
                }
                if(st.find(i) == st.end() && hasZero == false) st.insert(i);
            }       
        }
        return st.size();
    }
};