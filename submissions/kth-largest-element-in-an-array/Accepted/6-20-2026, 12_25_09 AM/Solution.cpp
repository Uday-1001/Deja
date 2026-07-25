// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int max_elem = *max_element(begin(nums) , end(nums));
        int min_elem = *min_element(begin(nums) , end(nums));

        vector<int>slots(max_elem - min_elem + 1 , 0);

        for(auto it : nums) slots[it - min_elem]++;

        int count = 0;
        for(int i = slots.size()-1 ; i>=0 ; i--)
        {
            count += slots[i];
            if(count >= k) return i + min_elem;
        }
        return -1;
    }
};