// https://leetcode.com/problems/first-unique-even-element

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int count[101] = {0};
        for(auto it : nums) count[it]++;

        for(auto it : nums){
            if(it % 2 == 0 and count[it] == 1) return it;
        }
        return -1;
    }
};