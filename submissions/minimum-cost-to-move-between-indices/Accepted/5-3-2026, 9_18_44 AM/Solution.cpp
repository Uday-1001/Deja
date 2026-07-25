// https://leetcode.com/problems/minimum-cost-to-move-between-indices

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>ans;
        vector<int>leftcost(n , 0);
        vector<int>rightcost(n , 0);

        for(int i = 0 ; i<n-1 ; i++){
            int cost = 0;
            if(i == 0) cost = 1;
            else {
                int leftdist = nums[i] - nums[i-1];
                int rightdist = nums[i+1] - nums[i];

                if(rightdist < leftdist) cost = 1;
                else cost = rightdist;
            }
            rightcost[i+1] = rightcost[i] + cost;
        }
        
        for(int i = n-1 ; i>0; i--){
            int cost = 0;
            if(i == n-1) cost = 1;
            else {
                int leftdist = nums[i] - nums[i-1];
                int rightdist = nums[i+1] - nums[i];

                if(leftdist <= rightdist) cost = 1;
                else cost = leftdist;
            }
            leftcost[i-1] = leftcost[i] + cost;
        }

        for(auto &it : queries){
            int st = it[0];
            int end = it[1];

            if(st < end){
                ans.push_back(rightcost[end] - rightcost[st]);
            }
            else if(st > end){
                ans.push_back(leftcost[end] - leftcost[st]);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};