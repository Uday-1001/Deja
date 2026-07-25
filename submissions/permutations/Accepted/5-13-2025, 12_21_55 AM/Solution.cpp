// https://leetcode.com/problems/permutations

class Solution {
public:
    void solve(vector<int>& nums , vector<vector<int>>&answer , int i)
    {
        //base case
        if(i >= nums.size())
        {
            answer.push_back(nums);
            return;
        }
        //ek case hum solve karenge baaki recursion sambhalega
        for(int j = i ; j<nums.size() ; j++)
        {
            swap(nums[i] , nums[j]);
            solve(nums , answer , i+1);

            //backtrack to revert the changes done by recursive calls 
            swap(nums[i] , nums[j]);
        }   
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;

        solve(nums , answer , 0);
        return answer;
    }
};