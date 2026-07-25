// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        
        for(int i = 0 ; i<words.size() ; i++)
        {
            if(words[i] == target)
            {
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;
                ans = min(ans , min(forward , backward));
            }
        }
        return ans == INT_MAX ? -1 : ans;        
    }
};