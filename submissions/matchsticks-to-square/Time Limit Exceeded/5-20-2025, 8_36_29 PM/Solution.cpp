// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool solve(vector<int>& match , vector<int>sides , int i)
    {
        //base case
        //iska matlab maine saari match sticks try kari hai aur jo  vector hai vo bhi 0 ho chuka hai 
        //means har side form ho chuki hai
        if(i >= match.size())
        {
            return (sides[1] == 0 && sides[2] == 0 && sides[3] == 0 && sides[4] == 0);
        }
        bool recursive_ans = false;
        //ek case hum solve karenge baaki ka kaam recursion sambhalega 
        for(int j = 0 ; j<sides.size() ; j++)
        {
            //include the matchstick to a side
            sides[j] -= match[i];
            recursive_ans = recursive_ans || solve(match , sides, i+1);
            //yha pr recursion final answer la chuka hoga har side se 
            if(recursive_ans == true)
            {
                return true;
            }
            //backtrack kr jao kyuki answer nhi aa paya is matchstick ko include karke
            sides[j] += match[i];
        }
        return recursive_ans;  
    }

    bool makesquare(vector<int>& match) {
        int n = match.size();
        int sum = accumulate(match.begin() , match.end() , 0);
        int side_sum = sum / 4;

        if(sum % 4 != 0) return false;

        vector<int>sides(n , side_sum);

        return solve(match , sides , 0);
    }
};