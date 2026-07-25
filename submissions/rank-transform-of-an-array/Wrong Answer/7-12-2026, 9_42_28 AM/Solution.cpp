// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        sort(begin(arr) , end(arr));
        vector<int>rank;

        int ranking = 1;
        rank.push_back(ranking);
        ranking++;

        for(int i = 1 ; i<arr.size() ; i++)
        {
            if(arr[i] == arr[i-1]) rank.push_back(ranking);
            else 
            {
                ranking++;
                rank.push_back((ranking));
            }
        }
        return rank;
    }
};