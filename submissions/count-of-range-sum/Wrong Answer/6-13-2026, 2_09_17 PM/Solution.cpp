// https://leetcode.com/problems/count-of-range-sum

class Solution {
public:
    vector<int>segTree;
    unordered_set<int>st;
    int totalnodes = 0;

    void BuildTree(vector<int>&nums , int i , int l , int r)
    {
        //base case
        if(l == r)
        {
            segTree[i] = nums[l];
            totalnodes++;
            return;
        }

        int mid = (l + r) >> 1;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;

        BuildTree(nums , leftchild , l , mid);
        BuildTree(nums , rightchild , mid+1 , r);

        //update the parent node
        totalnodes++;
        segTree[i] = segTree[leftchild] + segTree[rightchild];
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        segTree.resize(4*n);

        for(int i = lower ; i<=upper ; i++) st.insert(i);

        BuildTree(nums , 0 , 0 , n-1);

        int count = 0;
        int dummynodesused = 4*n - totalnodes;

        for(auto it : segTree) if(st.count(it)) count++;

        return count - dummynodesused;
    }
};