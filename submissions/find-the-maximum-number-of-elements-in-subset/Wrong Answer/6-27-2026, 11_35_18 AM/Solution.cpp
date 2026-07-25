// https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset

class Solution {
public:
    using ll = long long;

    int maximumLength(vector<int>& nums) {
        unordered_map<ll,int>mp;

        for(auto it : nums) mp[it]++;

        int maxlen = 1;

        if(mp.count(1))
        {
            int freq = mp[1];
            maxlen = max(maxlen , (freq % 2 == 0) ? freq - 1 : freq);
        }

        for(auto it : mp)
        {
            ll number = it.first;
            int freq = it.second;
            int len = 0;

            if(number == 1)  continue;
            while(mp.count(number) and freq >= 2)
            {
                len += 2;
                if(number > 1000000000LL) break;
                ll nextnumber = number * number;
                number = nextnumber;
            }

            if(mp.count(number)) len++;
            else len--;

            maxlen = max(maxlen , len);
        }
        return maxlen;
    }
};