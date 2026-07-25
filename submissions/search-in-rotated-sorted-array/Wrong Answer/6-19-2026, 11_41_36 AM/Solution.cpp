// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int s{} , e{n-1};

        while(s <= e)
        {
            cout<<s <<"->"<<e<<endl;
            int mid = s + (e-s)/2;

            if(nums[mid] == target) return mid;

            if(nums[s] < nums[mid])
            {
                //means that the left part is sorted
                if(nums[s] <= target and nums[mid] > target)
                {
                    //for sure it is in left part 
                    e = mid - 1;
                }
                else s = mid + 1;
            }
            else
            {
                //means that the right part is sorted
                if(nums[mid] <= target and nums[e] > target)
                {
                    //for sure it is in right part
                    s = mid + 1;
                }
                else e = mid - 1;
            }
        }
    return -1;
    }
};