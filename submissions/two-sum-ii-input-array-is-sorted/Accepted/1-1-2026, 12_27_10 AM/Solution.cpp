// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    int binarySearchresult(vector<int>&numbers , int to_find , int i)
    {
        int s = i+1;
        int e = numbers.size()-1;

        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(to_find == numbers[mid]) return mid;
            else if(to_find > numbers[mid]) s = mid + 1;
            else e = mid - 1;
        }
    return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0 ; i<n ; i++)
        {
            int to_find = target - numbers[i];
            int indexofsearch = binarySearchresult(numbers , to_find , i);
            if(indexofsearch != -1) return {i+1 , indexofsearch+1};
        }
    return {};
    }
};