// https://leetcode.com/problems/queries-on-a-permutation-with-key

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>permute(m);
        vector<int>ans;
        for(int i = 0 ; i<m ; i++) permute[i] = i+1;

        int index_req = 0;
        for(int i = 0 ; i < queries.size() ; i++)
        {
            for(int j = 0; j < permute.size() ; j++)
            {
                if(permute[j] == queries[i])
                {
                    index_req = j;
                    ans.push_back(j);
                    break;
                }
            }
            int to_be_inserted = permute[index_req];
            permute.erase(permute.begin() + index_req);
            permute.insert(permute.begin() , to_be_inserted);
        }
        return ans;
    }
};