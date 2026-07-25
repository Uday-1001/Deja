// https://leetcode.com/problems/find-the-winner-of-the-circular-game

class Solution {
public:

    int solve(int n, int k){
        // base case 
        if(n == 1) return 1;
        // 1 case hum solve karenge
        int peechewale = solve(n-1,k);
        int ans = (peechewale + k) % n;

        return ans;
    }

    int findTheWinner(int n, int k) {
        int ans = solve(n, k) - 1;
        return ans;
    }
};