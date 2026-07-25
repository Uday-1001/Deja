// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>freq(nums.size()+1 , 0);
        for(auto num : nums) freq[num]++;

        int duplicate = -1;
        int missed = -1;
        for(int i=1 ; i<=nums.size() ; i++)
        {
            if(freq[i] == 2) duplicate = i;
            if(freq[i] == 0) missed = i;
        }
        return {duplicate , missed};
    }
};