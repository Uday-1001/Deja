// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin() , arr.end());
        
        int min_diff = INT_MAX;
        for(int i = 0 ; i+1<arr.size() ; i++) 
        {
            min_diff = min(min_diff , arr[i+1] - arr[i]);
        }

        for(int i = 0 ; i+1 < arr.size() ; i++)
        {
            if(arr[i+1] - arr[i] == min_diff) ans.push_back({arr[i] , arr[i+1]});
        }
        
        return ans;
    }
};