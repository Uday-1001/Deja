// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    set<vector<int>>st;
    
    void recursion(vector<int>& nums , int i , vector<int>ans )
    {
        //base case
        if(i >= nums.size())
        {
            st.insert(ans);
            return;
        }
        //ek case hum solve karenge baaki recusion sambhalega 

        //include the element 
        ans.push_back(nums[i]);
        recursion(nums , i+1 , ans );

        //exclude
        ans.pop_back();
        recursion(nums , i+1 , ans );

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums) , end(nums));
        vector<vector<int>>final_arr;
        vector<int>ans;

        recursion(nums , 0 , ans );
        for(auto it : st)
        {
            final_arr.push_back(it);
        }
        return final_arr;
    }
};