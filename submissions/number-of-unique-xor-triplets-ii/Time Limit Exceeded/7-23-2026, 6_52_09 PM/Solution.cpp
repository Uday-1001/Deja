// https://leetcode.com/problems/number-of-unique-xor-triplets-ii

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i ; j<n ; j++)
            {
                int xorval = nums[i] ^ nums[j];

                for(int k = j ; k<n ; k++) st.insert(xorval ^ nums[k]);
            }
        }

        return st.size();
    }
};