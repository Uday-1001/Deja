// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

class Solution {
public:

    int hashmap[1001] = {0};
    vector<vector<int>>ans;

    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        for(auto vec1 : nums1)
        {
            int id = vec1[0];
            int val = vec1[1];

            hashmap[id] = val;
        }
        
        for(auto vec2 : nums2)
        {
            int id = vec2[0];
            int val = vec2[1];

            if(hashmap[id] > 0)
            {
                hashmap[id] += val;
            }
            else
            {
                hashmap[id] = val;
            }
        }

        for (int id = 1; id <= 1000; id++) 
        {
            if (hashmap[id] > 0) 
            {
                ans.push_back({id, hashmap[id]});
            }
        }
        return ans;
    }
};