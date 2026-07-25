// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;

        string prev = "";
        for(auto &word : words)
        {
            string curr = word;
            sort(begin(curr) , end(curr));
            if(curr != prev)
            {
                ans.push_back(word);
            }
            prev = curr;
        }
    return ans;
    }
};