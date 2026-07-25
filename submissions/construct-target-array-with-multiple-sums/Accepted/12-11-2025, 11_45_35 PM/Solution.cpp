// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>pq;
        long long sum = 0;

        if(target.size() == 1) return target[0] == 1;

        for(auto num : target)
        {
            pq.push(num);
            sum += num;
        } 

        while(true)
        {
            long long top = pq.top() ; pq.pop();
            long long valtosubtract = sum - top;

            if(top == 1 or valtosubtract == 1) return true;
            if(valtosubtract < 0 or top < valtosubtract) return false;

            long long leftval = top % valtosubtract;
            if(leftval == 0)  return false;
           
            sum = valtosubtract + leftval;
            pq.push(leftval);
        }
        return false;
    }
};