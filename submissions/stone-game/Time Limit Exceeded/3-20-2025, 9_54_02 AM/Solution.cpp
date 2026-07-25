// https://leetcode.com/problems/stone-game

class Solution {
public:
    int solve(vector<int>& piles , int i , int j)
    {
        //base case
        if(i>j) return 0;
        //single score
        if(i==j) return piles[i];
        
        int taking_i = piles[i] + min(solve(piles,i+2,j) , solve(piles,i+1,j-1));
        
        int taking_j = piles[j] + min(solve(piles,i+1,j-1) , solve(piles,i,j-2));

        return max(taking_i , taking_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        int total_score = accumulate(piles.begin() , piles.end() , 0);
        int alice = solve(piles,0,n-1);
        int bob = total_score - alice;
        return alice >= bob;
    }
};