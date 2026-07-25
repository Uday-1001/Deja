// https://leetcode.com/problems/24-game

class Solution {
public:
    double max_diff = 0.000001;
    bool solve(vector<double>&cards)
    {
        //base case 
        if(cards.size() == 1)
        {
            return (cards[0] == 24);
        }

        //recursion bhaiya aage ka exploration karenge 
        for(int i= 0 ; i<cards.size() ; i++)
        {
            for(int j=0 ; j<cards.size() ; j++)
            {
                //dont pick the same cards
                if(i == j) continue;

                //make a new array of the elements except those of ith and jth position 
                vector<double>temp;
                for(int k =0 ; k<cards.size(); k++)
                {
                    if(k != i && k != j)
                    {
                        temp.push_back(cards[k]);
                    }
                }

                //picking the two elements 
                double a = cards[i];
                double b = cards[j];

                //make an array of all the possible operations
                vector<double>possibleops;
                possibleops = {a+b , a*b , a-b , b-a};

                //check for valid division operation
                if(b > 0.0)
                {
                    possibleops.push_back(a/b);
                }
                if(a > 0.0)
                {
                    possibleops.push_back(b/a);
                }
                //to copy the last operated result 
                for(auto val : possibleops)
                {
                    //do the result
                    temp.push_back(val);
                    //explore for the true result else
                    if(solve(temp) == true)
                    {
                        return true;
                    }
                    //backtrack the path
                    temp.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(int i =0; i<cards.size() ; i++)
        {
            nums.push_back(cards[i]);
        }

        return solve(nums);
    }
};