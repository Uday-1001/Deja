// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void swap_when_greater(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2)
    {
        //runtime checking condition so that the nums2 vector is not empty
        if(nums2.size() == 0) return;

        if(idx1 >= nums1.size() || idx2 >= nums2.size()) return;

        if(nums1[idx1] > nums2[idx2])
        {
            swap(nums1[idx1] , nums2[idx2]);
        }
    }

    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
                // SWAP WHEN GREATER TECHNIQUE

        // int left = n-1;
        // int right = 0;

        // while(left >= 0 && right < m)
        // {
        //     if(nums1[left] >= nums2[right])
        //     {
        //         swap(nums1[left] , nums2[right]);
        //         left--;
        //         right ++;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // sort(nums1.begin() , nums1.begin() + n);
        // sort(nums2.begin() , nums2.end());

        // for(int i = 0 ; i<m ; i++)
        // {
        //     nums1[i+n] = nums2[i];
        // }     


                // GAP METHOD -> FROM SHELL SORT

        int len = n + m;
        int gap = (len / 2) + (len % 2);//same thing for ceil(len / 2)

        while(gap > 0)
        {
            int left = 0;
            int right = left + gap;

            while(right < len)
            {
                //i am in arr1 for left and arr2 for right
                if(left < n && right >= n)
                {
                    swap_when_greater(nums1 , left , nums2 , right - n);
                }
                //i am in arr2 for both left and right 
                else if(left >= n)
                {
                    swap_when_greater(nums1 , left - n , nums2 , right - n);
                }
                //i am in arr1 for both left and right
                else
                {
                    if(right < m)
                    swap_when_greater(nums1 , left , nums2 , right);
                }
                left ++;
                right ++;
            }
            //updation of thr gap after each iteration
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        
            for(int i= 0 ; i<m ; i++)
            {
                nums1[n + i] = nums2[i];
            }
    }
};