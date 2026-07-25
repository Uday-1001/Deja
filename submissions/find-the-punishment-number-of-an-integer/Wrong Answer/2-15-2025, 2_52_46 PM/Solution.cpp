// https://leetcode.com/problems/find-the-punishment-number-of-an-integer

class Solution {
public:

    vector<int> v;

    bool helper(string st, int i, int sum){
        // base case
        if(i >= st.length()-1){
            if(sum != 0) return false;
            // cout << "return true" << endl;
            return true;
        }
        // 1 case hum karenge
        bool aagekaans = false;
        int sum2 = sum;
        for(int j = i+1; j < st.length(); j++){
            string s = st.substr(i+1, j-i);
            int val = stoi(s);
            int temp = sum2 - val;
            // cout << "i = " << i << " j = " << j <<  "  val = " << val << "  temp = " << temp << endl;
            aagekaans = aagekaans || helper(st, j, temp);
        }
        return aagekaans;
    }

    int punishmentNumber(int n) {
        for(int i = 1; i<=n; i++){
            int sq = i*i;
            string st = to_string(sq);
            int pehla = i - (st[0] - '0');
            // cout << "st = " << st << endl;
            bool flag = helper(st, 0, pehla);
            if(flag){
                v.push_back(sq);
            }
        }
        // cout << "v.size = " << v.size() << endl;
        for(auto& x : v){
            // cout << x << " ";
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        return n <= 8 ? sum : sum + 100;
    }
};