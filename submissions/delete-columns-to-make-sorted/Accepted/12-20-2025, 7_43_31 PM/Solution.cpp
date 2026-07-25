// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        set<int>st;
        for(int col = 0; col<strs[0].size() ; col++)
        {
            for(int row = 1 ; row<strs.size() ; row++)
            {
                if(strs[row][col] < strs[row-1][col])
                {
                    st.insert(col);
                    break;
                } 
            }
        }
    return st.size();
    }
};