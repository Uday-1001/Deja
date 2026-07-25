// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    void recursion(vector<int>& nums , int i , vector<int>& subsets , vector<int>&ans)
    {
        //base cases
        if(i >= nums.size()) 
        {
            if(subsets.size() > ans.size())
            {   
                ans = subsets;
            }
            return;
        }

        //ek case hum solve krenge baaki recursion sambhalega

        //include with condition
        if(subsets.empty() || nums[i] % subsets.back() == 0)
        {
            subsets.push_back(nums[i]);
            recursion(nums , i+1 , subsets , ans);
            //ftaak se hta do ye element ko
            subsets.pop_back();
        } 
        //exclude
        recursion(nums , i+1 , subsets , ans);
        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int>ans;
        vector<int>subsets;
        recursion(nums , 0 , subsets , ans);
        return ans;


    }
};