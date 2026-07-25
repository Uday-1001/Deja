// https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
    //     int n = nums.size();
    //     int non_increasing_elems = 0;
    //     for(int i = n-2 ; i>=0 ; i--){
    //         if(nums[i] < nums[i+1]) continue;
    //         else
    //         {
    //             non_increasing_elems = i + 1;
    //             break;
    //         }
    //     }
    // return non_increasing_elems;


    //Second method

    int n = nums.size();

    vector<int>inc(n , 1);

    for(int i = 0 ; i+1<n ; i++)
    {
        if(nums[i] < nums[i+1]) inc[i] = 1;
        else inc[i] = 0;
    }
    inc[n-1] = 1;

    int first_zero = -1;
    for(int i = n-2 ; i >= 0 ;i--)
    {
        if(inc[i] == 0) 
        {
            first_zero = i;
            break;
        }
    }
    return first_zero == -1 ? 0 : first_zero + 1;
    }
};