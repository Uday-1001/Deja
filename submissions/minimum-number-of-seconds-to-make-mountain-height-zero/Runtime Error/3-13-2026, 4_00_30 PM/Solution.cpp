// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero

class Solution {
public:
    using ll = long long;
    
    bool ZyadaPhodDiyaYaNhi(int height , vector<int>&time , ll mid)
    {
        ll total = 0;
        for(auto t : time)
        {
            ll val = (2 * mid) / t;
            ll x = (sqrt(1 + 4 * val) - 1) / 2; 
            total += x;
        }
        return total >= height;
    }

    ll BS(int height, vector<int>& time)
    {
        ll s = 1;
        ll e = *max_element(begin(time) , end(time)) * ((height * (height+1)) / 2);
        ll ans = -1;

        while(s <= e)
        {
            ll mid = s + (e-s)/2;   
            if(ZyadaPhodDiyaYaNhi(height , time , mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
    return ans;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        return BS(mountainHeight , workerTimes);
    }
};