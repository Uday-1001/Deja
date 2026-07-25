// https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mp;

        for(int i = 0 ; i<n ; i++){
            mp[nums1[i]]++;
            mp[nums2[i]]--;
        }

        int ans = 0;
        for(auto it : mp){
            if(abs(it.second) % 2 != 0) return -1;
            if(it.second > 0) ans += it.second / 2;
        }
    return ans;
    }
};