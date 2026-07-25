// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin() , arr.end());
        
        int min_diff = arr[1] - arr[0];
        ans.push_back({arr[0] , arr[1]});

        for(int i = 1 ; i+1<arr.size() ; i++)
        {
            if(arr[i+1] - arr[i] == min_diff) ans.push_back({arr[i] , arr[i+1]});
        }
        return ans;
    }
};