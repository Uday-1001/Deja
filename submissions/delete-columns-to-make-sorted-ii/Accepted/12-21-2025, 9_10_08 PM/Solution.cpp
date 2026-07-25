// https://leetcode.com/problems/delete-columns-to-make-sorted-ii

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int to_be_deleted = 0;
        vector<bool> is_Sorted(n-1,false);

        for(int col=0; col<m; col++)
        {
            bool del = false;
            for(int row=0; row < n-1; row++)
            {
                if(strs[row][col] > strs[row+1][col] && is_Sorted[row] == false)
                {
                    del = true;
                    to_be_deleted++;
                    break;
                }
            }
            if(del) continue;
            for(int i=0; i<n-1; i++){
                is_Sorted[i] = is_Sorted[i] or (strs[i][col] < strs[i+1][col]);
            }
        }
        return to_be_deleted;
    }
};