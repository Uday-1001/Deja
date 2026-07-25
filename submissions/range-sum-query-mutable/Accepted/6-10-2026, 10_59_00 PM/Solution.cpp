// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    int n;
    vector<int>segTree;

    void BuildTree(vector<int>&nums , int idx , int l , int r)
    {
        //base case 
        if(l == r) 
        {
            segTree[idx] = nums[r];
            return;
        }

        int mid = (l + r) >> 1;
        int leftchild = 2*idx + 1;
        int rightchild = 2*idx + 2;

        //Building the left tree
        BuildTree(nums , leftchild , l , mid);
        BuildTree(nums , rightchild , mid+1 , r);

        //summing up the values of left and right child to the parent 
        segTree[idx] = segTree[leftchild] + segTree[rightchild];
    }

    void UpdateTree(int pos , int val , int i , int l , int r)
    {
        //base case
        if(l == r)
        {
            segTree[i] = val;
            return;
        }

        int mid = (l + r) >> 1;
        int leftchild = 2*i + 1;
        int rightchild = 2*i + 2;

        if(pos <= mid)
        {
            //this means that the range is in left tree
            UpdateTree(pos , val , leftchild , l , mid);
        }
        else 
        {
            //this means that the range is in right tree
            UpdateTree(pos , val , rightchild , mid+1 , r);
        }

        //updating the parent node as the left and right children are also updated
        segTree[i] = segTree[leftchild] + segTree[rightchild];
    }

    int QueryTree(int st , int end , int i , int l , int r)
    {
        // out of bounds from both sides --> return 0
        if(l > end or r < st) return 0;
        
        //overall query is in the range --> return the parent node value
        if(l >= st and r <= end) return segTree[i];

        //partial inclusion of the query in the range --> get ans from both left and right and return the sum of it
        int mid = (l + r) >> 1;
        int leftchild = 2*i + 1;
        int rightchild = 2*i + 2;

        return QueryTree(st , end , leftchild , l , mid) + QueryTree(st , end , rightchild , mid+1 , r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);

        BuildTree(nums , 0 , 0 , n-1);
    }
    
    void update(int index, int val) {
        UpdateTree(index , val , 0 , 0 , n-1);
    }
    
    int sumRange(int left, int right) {
        return QueryTree(left , right , 0 , 0 , n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */