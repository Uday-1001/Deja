// https://leetcode.com/problems/sort-an-array

class Solution {
public:

    void merger2sortedarray(vector<int>& nums, int s, int e, int mid){
        int leftlen = mid - s + 1;
        int rightlen = e - mid;
        int left[leftlen];
        int right[rightlen];

        // actual array me se copy karenge left and right array me
        int index = 0;
        for(int i = s; i<=mid; i++){
            left[index] = nums[i];
            index++;
        }
        index = 0;
        for(int i = mid+1; i<=e; i++){
            right[index] = nums[i];
            index++;
        }

        // merge 2 sorted array -> actual merge 2 sorted array ka code
        int i = 0, j= 0;
        int mainarrayindex = s;
        while(i<leftlen && j<rightlen){
            if(left[i] < right[j]){
                nums[mainarrayindex] = left[i];
                mainarrayindex++;
                i++;
            }
            else{
                nums[mainarrayindex] = right[j];
                mainarrayindex++;
                j++;
            }
        }
        // ho sakta hai ki j khatam ho jaye i baacha ho
        while(i < leftlen){
            nums[mainarrayindex] = left[i];
            mainarrayindex++;
            i++;
        }
        // ho sakta hai ki i khatam ho jaye j baacha ho
        while(j < rightlen){
            nums[mainarrayindex] = right[j];
            mainarrayindex++;
            j++;
        }
    }

    void mergesort(vector<int>& nums, int s, int e){
        // base case
        if(s == e) return;
        // if(s > e) return;
        // recursive call
        int mid = s + (e-s)/2;
        mergesort(nums, s, mid);
        mergesort(nums, mid+1, e);
        // backtracking
        merger2sortedarray(nums, s, e, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        mergesort(nums, s, e);
        return nums;
    }
};