// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    void solve(vector<int>&perm , int &n , int &count , int current)
    {
        //base case 
        //agar perm full ho jaye to ans mil gya hai
        if(current == n+1)
        {
            count ++;
            return;
        }
        //ek case hum solve karenge baaki recursion kardega 
        for(int i =1 ; i<=n ; i++)
        {
            if(perm[i] == 0 && (current % i == 0 || i % current == 0))
            {
                //put the number at that place
                perm[i] = current;
                //recursive calling
                solve(perm , n , count , current + 1);

                //backtracking
                perm[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>perm(n+1);
        int count = 0;

        solve(perm , n , count , 1);
        return count;
    }
};