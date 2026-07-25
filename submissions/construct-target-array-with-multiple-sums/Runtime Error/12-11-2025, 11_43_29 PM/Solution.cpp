// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        int sum = 0;

        for(auto num : target)
        {
            pq.push(num);
            sum += num;
        } 

        int onescount = 0;
        while(true)
        {
            int top = pq.top() ; pq.pop();
            int valtosubtract = sum - top;

            if(top == 1 or valtosubtract == 1) return true;
            if(valtosubtract < 0 or top < valtosubtract) return false;

            int leftval = top % valtosubtract;
            if(leftval == 0)  return false;
           
            sum = valtosubtract + leftval;
            pq.push(leftval);
        }
        return false;
    }
};