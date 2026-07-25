// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>newarr = arr;
        sort(begin(newarr) , end(newarr));
        newarr.erase(unique(begin(newarr) , end(newarr)) , end(newarr));
        vector<int>rank;

        for(auto it : newarr) cout<<it<<" ";

        for(int i = 0 ; i<arr.size() ; i++)
        {
            int findindexinsorted = lower_bound(begin(newarr) , end(newarr) , arr[i]) - newarr.begin();
            rank.push_back(findindexinsorted + 1);
        }

        return rank;
    }
};