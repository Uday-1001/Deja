// https://leetcode.com/problems/count-monobit-integers

class Solution {
public:
    string binary(int n)
    {
        string ans = "";
        while(n > 0){
            char d = n % 2;
            ans.push_back(d + '0');
            n /= 2;
        }    
        reverse(ans.begin() , ans.end());
        return ans;
    }

    bool samesame(string num)
    {
        set<char>st;
        for(auto it : num) st.insert(it);
        return st.size() == 1;        
    }
    
    int countMonobit(int n) {
        int count = 2;
        if(n == 0) return 1;
        for(int i = 2 ; i<=n ; i++){
            string number = binary(i);
            cout<<number<<endl;
            if(samesame(number)) count++;
        }
        return count;
    }
};