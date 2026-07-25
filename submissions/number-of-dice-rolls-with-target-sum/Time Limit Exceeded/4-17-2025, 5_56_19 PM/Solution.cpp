// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    int mod = 1000000007;

    int recursion(int n, int k, int target )
    {
        //base cases

        //jab mera target sum aagya ho aur dices bhio finish ho chuke ho 
        if(n == 0 && target == 0) return 1;

        //jab mera target nhi aaya ho but dices finish ho gye hai
        if(n == 0 || target <= 0) return 0;

        //ek case hum solve karenge baaki recursion karlega 
        int way = 0;
        for(int i =1 ; i<=k ; i++)
        {
            way = (way + recursion(n-1 , k , target - i)) % mod; 
        }
        return way;
    }

    int numRollsToTarget(int n, int k, int target) {
        int ans = recursion(n , k , target);
        return ans;
    }
};