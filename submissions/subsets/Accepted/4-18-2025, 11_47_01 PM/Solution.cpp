// https://leetcode.com/problems/subsets

class Solution {
public:
    void recursion(vector<int>& nums , int i , vector<int>&ans , vector<vector<int>>&final_arr)
    {
        //base case
        if(i >= nums.size())
        {
            final_arr.push_back(ans);
            return;
        }
        //ek case hum solve karenge baaki recusion sambhalega 

        //include the element 
        ans.push_back(nums[i]);
        recursion(nums , i+1 , ans , final_arr);

        //exclude
        ans.pop_back();
        recursion(nums , i+1 , ans , final_arr);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>final_arr;
        vector<int>ans;

        recursion(nums , 0 , ans , final_arr);
        return final_arr;
    }
};