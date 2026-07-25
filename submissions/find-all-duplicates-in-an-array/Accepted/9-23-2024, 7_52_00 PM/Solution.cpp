// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
     {
        vector<int>arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                arr.push_back(nums[i]);
            }
           
        } return arr ;
    
     }        

};