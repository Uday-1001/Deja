// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    int byrec(vector<vector<int>>&pairs , int prev , int curr)
    {
        //base case
        if(curr >= pairs.size()) return 0;

        //ek case hum solve karenge 
        int include = 0;
        if(prev == -1 or pairs[prev][1] < pairs[curr][0])
        {
            include = 1 + byrec(pairs , curr , curr+1);
        }
        int exclude = 0 + byrec(pairs , prev , curr+1);

        return max(include , exclude);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        return byrec(pairs ,-1 , 0);

    }
};