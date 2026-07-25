// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> byrec(vector<int>& nums , int i , vector<int>& subsets)
    {
        //base cases
        if(i >= nums.size()) return subsets;

        //include
        vector<int>include , exclude;

        if(subsets.empty() || nums[i] % subsets.back() == 0)
        {
            subsets.push_back(nums[i]);
            include = byrec(nums , i+1 , subsets);
            //ftaak se hta do ye element ko
            subsets.pop_back();
        } 
        //exclude
        exclude = byrec(nums , i+1 , subsets);

        return (include.size() > exclude.size()) ? include : exclude;
        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int>subsets;
        return byrec(nums , 0 , subsets);
    }
};