// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<int>&nums , int index)
    {
        //base case 
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        //ek case hum solve karenge
        unordered_map<int,bool>marked;

        for(int i= index ; i<nums.size() ; i++)
        {
            if(marked.find(nums[i]) != marked.end())
            {
                continue;
            }
            marked[nums[i]] = true;
            //include
            swap(nums[i] , nums[index]);
            //recursive calling
            solve(ans , nums, index + 1);

            //bakctracking
            swap(nums[i] , nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;

        solve(ans , nums , 0);
        return ans;
    }
};