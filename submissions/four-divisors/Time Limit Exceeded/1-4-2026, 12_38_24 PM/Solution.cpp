// https://leetcode.com/problems/four-divisors

class Solution {
public:
    vector<int> getdivisors(int n)
    {
        vector<int>ans;
        ans.push_back(1);
        for(int i = 2 ; i<=n; i++)
        {
            if(n % i == 0) ans.push_back(i);
        }
    return ans;
    }

    int sumFourDivisors(vector<int>& nums) {
        map<pair<int,int> , vector<int>>mp;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            vector<int>divisors = getdivisors(nums[i]);
            if(divisors.size() < 4 or divisors.size() > 4) continue; 
            mp[{nums[i] , i}] = divisors;
        }

        int sum = 0;
        for(auto &it : mp)
        {
            auto [num , idx] = it.first;
            auto vec = it.second;
            if(vec.size() == 4)
            {
                for(auto n : vec) sum += n;
            }
        }
    return sum;
    }
};