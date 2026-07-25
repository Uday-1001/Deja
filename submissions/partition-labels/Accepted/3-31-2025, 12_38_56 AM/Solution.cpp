// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        // store the last occurence of each character
        for(int i=0 ; i<s.size() ; i++)
        {
            mp[s[i]-'a'] = i;
        }

        int i = 0;
        while(i < s.size())
        {
            int last_index = mp[s[i]-'a'];
            int j = i;
            while(j<last_index)
            {
                last_index = max(last_index , mp[s[j]-'a']);
                j++;
            }    
        ans.push_back(j-i+1);  
        i = j+1;
        }
    return ans;
    }
};