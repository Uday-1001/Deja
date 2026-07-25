// https://leetcode.com/problems/sort-integers-by-binary-reflection

class Solution {
public:
    static long long reflection(int x)
    {
        if(x == 0) return 0;
        string ans = "";
        while(x > 0)
        {
            ans.push_back((x % 2) + '0');
            x /= 2;
        }
        int i = 0;
        long long num = 0;

        while(ans[i] == '0') i++;
        ans = ans.substr(i);
        if(ans.empty()) ans = "0";
        
        for(char ch : ans)
        {
            num = num * 2 + (ch - '0');
        }
        return num;
    }
    
    static bool mycomp(int a , int b){
        long long ra = reflection(a);
        long long rb = reflection(b);

        if(ra == rb) return a < b;
        else return ra < rb;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin() , nums.end() , mycomp);
        return nums;
    }
};