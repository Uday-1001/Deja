// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;

        sort(begin(nums) , end(nums));

        map<int , int>mp;

        for(auto it : nums) mp[it]++;

        for(auto it : nums)
        {
            if(mp.empty()) break;
            
            int next = mp.begin()->first;
            for(int i = 0 ; i<k ; i++)
            {
                if(mp.count(next)) 
                {
                    mp[next]--;
                    if(mp[next] == 0) mp.erase(next);
                    next++;
                }
                else return false;
            }
        }
        return true;
    }
};