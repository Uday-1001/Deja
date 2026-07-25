// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions) , end(potions));
        vector<int>ans(spells.size());

        int total = potions.size();

        for(int i =0 ; i<spells.size() ; i++)
        {
            int s = 0;
            int e = potions.size()-1;
            int curr_spell = spells[i];
            int count = -1;
            while(s<=e)
            {
                int mid = s + (e-s)/2;
                if((long long)spells[i] * (long long)potions[mid] >= success)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            count = total - e - 1;
            ans[i] = count;
        }
    return ans;
    }
};