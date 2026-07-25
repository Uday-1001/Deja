// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            string temp = "";
            for(int j=0;j<n;j++){
                if(j == 0){
                    temp.push_back('a');
                }
                else if(matrix[i][j] == matrix[i][j-1]){
                    temp.push_back(temp[temp.length()-1]);
                }
                else{
                    char store = temp[temp.length()-1] == 'a' ? 'b' : 'a';
                    temp.push_back(store);
                }
            }
            mp[temp]++;
        }
        int ans = INT_MIN;
        for(auto it : mp){
            if(it.second > ans) ans = it.second;
        }
        return ans;
    }
};