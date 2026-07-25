// https://leetcode.com/problems/3sum

class Solution {
public:
    // TLE de rha hai kyuki optimized nhi hai na..
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>set;
        vector<vector<int>>output;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0 && i!=j && j!=k && k!=i){
                      set.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
    }
    for(auto i:set){
    output.push_back(i);
    }
    return output;
    }

};