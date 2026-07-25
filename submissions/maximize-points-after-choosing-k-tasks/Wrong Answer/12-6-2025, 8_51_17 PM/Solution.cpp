// https://leetcode.com/problems/maximize-points-after-choosing-k-tasks

class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<int>gain;
        for(int i=0; i<technique1.size() ; i++){
            gain.push_back(technique1[i] - technique2[i]);
        }
        sort(gain.rbegin() , gain.rend());
        
        int totaltech2 = accumulate(technique2 .begin() , technique2.end() , 0);
        int totaltech1 = accumulate(technique1 .begin() , technique1.end() , 0);
        int x = 0;
        for(int i =0; i<k ; i++){
            totaltech2 += gain[i];
        }
        return totaltech2 > totaltech1 ? totaltech2 : totaltech1;
    }
};