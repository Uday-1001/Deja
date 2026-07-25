// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool solve(vector<int>&match , vector<int>&sides , int i , int n)
    {
        //base case 
        if(i >= n)
        {
            //iska matlab tum saari matchsticks ko dekh chuke ho use krke
            return(sides[1] == 0 && sides[2] == 0 && sides[3] == 0 && sides[4] == 0);
        }
        //ek case hum solve karenge baaki ka recursion dekhega
        bool recursive_ans = false;
        for(int j =0 ; j<sides.size() ; j++)
        {
            //includ the matchstick
            sides[j] -= match[i];
            //recursive call
            recursive_ans = recursive_ans || solve(match , sides , i+1 , n);
            if(recursive_ans == true)
            {
                return true;
            }
            //backtrack kar jao kyuki ye current matchstick include nhi ho sakti hai
            sides[j] += match[i];
        }
        return recursive_ans;
    }

    bool makesquare(vector<int>& match) {
        int n = match.size();
        int totalsum = accumulate(begin(match) , end(match) , 0);
        int target_sum = totalsum / 4;

        if(totalsum % 4 != 0) return false;

        vector<int>sides(n , target_sum);
        return solve(match , sides , 0 , n);
    }
};