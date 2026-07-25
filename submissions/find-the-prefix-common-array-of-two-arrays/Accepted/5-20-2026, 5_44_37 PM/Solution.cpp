// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;

        int count = 0;
        vector<int>ans;
        
        for(int i = 0 ; i<A.size() ; i++)
        {
            mp[A[i]]++;
            mp[B[i]]++;
            
            if(mp[A[i]] == 2) count++;
            if(mp[B[i]] == 2) count++;
            if(A[i] == B[i]) count--;
            ans.push_back(count);
        }
        return ans;
    }
};