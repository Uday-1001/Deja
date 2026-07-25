// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans = INT_MAX;
        int idx=startIndex;
        for(int i = 0 ; i<words.size() ; i++)
        {
            if(words[idx%n]==target){
                ans=min(ans,min(idx-startIndex,n-(idx-startIndex)));
            }
            idx++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};