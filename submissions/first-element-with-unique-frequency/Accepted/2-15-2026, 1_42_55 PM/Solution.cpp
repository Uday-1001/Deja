// https://leetcode.com/problems/first-element-with-unique-frequency

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(int x : nums) freq[x]++;

        unordered_map<int, int>freqCount;
        for(auto p : freq) freqCount[p.second]++;
        

        for(int x : nums){
            if (freqCount[freq[x]] == 1) {
                return x;
            }
        }

        return -1;
    }
};