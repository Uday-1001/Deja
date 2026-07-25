// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet

class Solution {
public:
    vector<int>segTree;

    void BuildTree(vector<int>&heights , int i , int l , int r)
    {
        //base case
        if(l == r)
        {
            segTree[i] = l;
            return;
        }

        int mid = (l + r) / 2;
        int leftchild = 2*i + 1;
        int rightchild = 2*i + 2;

        BuildTree(heights , leftchild , l , mid);
        BuildTree(heights , rightchild , mid+1 , r);
        
        int leftmax = segTree[leftchild];
        int rightmax = segTree[rightchild];

        if(heights[leftmax] >= heights[rightmax]) segTree[i] = leftmax;
        else segTree[i] = rightmax;
    }

    int RangeMaxIndexQuery(vector<int>&heights , int st , int end , int i , int l , int r)
    {
        //out of bounds range
        if(l > end or r < st) return -1;

        //full range inside the query range
        if(st <= l and r <= end) return segTree[i];

        //overlapping case
        int mid = (l + r) / 2;
        int leftchild = 2*i + 1;
        int rightchild = 2*i + 2;

        int leftmaxidx = RangeMaxIndexQuery(heights , st , end , leftchild , l , mid);
        int rightmaxidx = RangeMaxIndexQuery(heights , st , end , rightchild , mid+1 , r);

        if(leftmaxidx == -1) return rightmaxidx;
        if(rightmaxidx == -1) return leftmaxidx;

        if(heights[leftmaxidx] >= heights[rightmaxidx]) return leftmaxidx;
        return rightmaxidx;
    }

    bool isBigger(vector<int>&heights , int possibleansidx , int l, int r)
    {
        return (heights[possibleansidx] > heights[l] and heights[possibleansidx] > heights[r]);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree.resize(4 * n);

        BuildTree(heights , 0 , 0 , n-1);

        vector<int>ans;

        for(auto it : queries)
        {
            int st = min(it[0] , it[1]);
            int end = max(it[0] , it[1]);

            if(heights[end] > heights[st]) ans.push_back(end);
            else if(st == end) ans.push_back(st);
            else
            {
                int stpt = end+1;
                int endpt = heights.size()-1;

                int reqans = -1;
                while(stpt <= endpt)
                {
                    int mid = stpt + (endpt - stpt) / 2;
                    int possibleansidx = RangeMaxIndexQuery(heights , stpt , mid , 0 , 0 , n-1);

                    if(possibleansidx != -1 and isBigger(heights , possibleansidx , st , end))
                    {
                        reqans = possibleansidx;
                        endpt = mid - 1;
                    }
                    else stpt = mid + 1;
                }
                ans.push_back(reqans);
            }
        }
    return ans;
    }
};