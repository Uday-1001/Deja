// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0 , j = nums.size()-1;
        vector<int>newone;
        vector<int>ans;

        for(auto it : nums) newone.push_back(abs(it));

        while(i < j)
        {
            if(newone[i] < newone[j]) j--;
            else if(newone[i] > newone[j]) 
            {
                swap(newone[i] , newone[j]);
                j--;
            }
            else i++;
        }


        for(auto it : newone) ans.push_back(it * it);
        return ans;
    }
};