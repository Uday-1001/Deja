// https://leetcode.com/problems/word-squares-ii

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& s) {
        int n = s.size();
        sort(s.begin() , s.end());
        vector<vector<string>>ans;

        for(int top = 0 ; top < n ; top++)
        {
            for(int left = 0 ; left < n ; left++)
            {
                if(left != top && s[top][0] == s[left][0])
                {
                    for(int right = 0 ; right < n ; right++)
                    {
                        if(right != left && right != top && s[top][3] == s[right][0])
                        for(int bottom = 0 ; bottom < n ; bottom++)
                        {
                            if(bottom != right && bottom != left && bottom != top &&
                            s[bottom][0] == s[left][3] && s[bottom][3] == s[right][3])
                            {
                                ans.push_back({s[top] , s[left] , s[right] , s[bottom]});
                            }
                        }
                    }
                }
            }
        }
    return ans;
    }
};