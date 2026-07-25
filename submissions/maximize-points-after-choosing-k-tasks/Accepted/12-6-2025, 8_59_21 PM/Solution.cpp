// https://leetcode.com/problems/maximize-points-after-choosing-k-tasks

class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<long long>gain;
        for(int i=0; i<technique1.size() ; i++){
            gain.push_back((long long)technique1[i] - technique2[i]);
        }
        sort(gain.rbegin() , gain.rend());
        
        long long totaltech2 = accumulate(technique2 .begin() , technique2.end() , 0LL);
        long long x = 0;
        for(int i =0; i<k ; i++){
            totaltech2 += gain[i];
        }

        for(int i=k ; i < gain.size() ; i++){
            if(gain[i] > 0) totaltech2 += gain[i];
        }
        return totaltech2;
    }
};