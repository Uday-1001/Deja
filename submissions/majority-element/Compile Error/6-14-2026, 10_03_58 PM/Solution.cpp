// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(count == 0)
            {
                count = 1;
                elem = nums[i];
            }
            cout<<count<<endl;
            if(elem == nums[i]) 
            {
                count++;
            cout<<count<<endl;
            }

            else 
            {
                count--;
        }
        return elem;
    }
};