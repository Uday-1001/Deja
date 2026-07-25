// https://leetcode.com/problems/sort-integers-by-binary-reflection

class Solution {
public:
    static long long reflection(int x)
    {
        long long r = 0;
        while(x > 0){
            r = (r << 1) | (x & 1);
            x = x >> 1;
        }
        return r;
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