// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    int solve(vector<int>& nums , int i , int j)
    {
        //base case
        if(i>j) return 0;
        //single score
        if(i==j) return nums[i];
        
        int taking_i = nums[i] + min(solve(nums,i+2,j) , solve(nums,i+1,j-1));
        
        int taking_j = nums[j] + min(solve(nums,i+1,j-1) , solve(nums,i,j-2));

        return max(taking_i , taking_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(nums.begin(), nums.end() , 0);
        int player1 = solve(nums , 0 , n-1);
        int player2 = total_score - player1;
        return player1 >= player2;
    }
};