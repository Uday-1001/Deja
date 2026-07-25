// https://leetcode.com/problems/delete-columns-to-make-sorted-iii

class Solution {
public:
    bool checkstring(vector<string>&strs , int prev , int curr)
    {
        for(int k = 0 ; k < strs.size() ; k++)
        {
            if(strs[k][prev] > strs[k][curr]) return false;
        }
    return true;
    }

    int byrec(vector<string>&strs , int prev , int curr)
    {
        //base case 
        if(curr >= strs[0].size()) return 0;

        int ans = INT_MAX;
        int dont_remove = 0;
        if(prev == -1 or checkstring(strs , prev , curr))
        {
            dont_remove = 0 + byrec(strs , curr , curr + 1);
            ans = min(ans , dont_remove);
        }
        int remove = 1 + byrec(strs , prev , curr + 1);
        ans = min(ans , remove);

        return ans;
    }
    int minDeletionSize(vector<string>& strs) {
        return byrec(strs , -1 , 0) == INT_MAX ? 0 : byrec(strs , -1 , 0);
    }
};