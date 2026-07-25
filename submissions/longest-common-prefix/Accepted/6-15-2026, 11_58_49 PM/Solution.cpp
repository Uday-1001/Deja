// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 1) return strs[0];

        vector<int>pointers(strs.size() , 0);

        while(true)
        {
            bool isSame = true;
            char ch = strs[0][pointers[0]];

            for(int i = 1 ; i<strs.size() ; i++)
            {
                if(pointers[i] >= strs[i].size() or strs[i][pointers[i]] != ch)
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame)
            {
                ans.push_back(ch);
                for(int i = 0 ; i<pointers.size() ; i++) pointers[i]++;
            }
            else break;
        }
        return ans;
    }
};