// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> map;
        int total_count = 0;

        for(int i= 0; i<nums.size(); i++)
        {
            for(int j =i+1; j<nums.size(); j++)
            {
                int product = nums[i] * nums[j];
                map[product]++;
            }
        }
        for(auto it : map)
            {
                int freq = it.second;
                if(freq > 0){
                    total_count += (freq * (freq-1)) / 2;
                }
            }
        return total_count * 8;
    }
};