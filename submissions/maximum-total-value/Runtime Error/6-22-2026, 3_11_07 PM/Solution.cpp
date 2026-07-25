// https://leetcode.com/problems/maximum-total-value

class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        priority_queue<tuple<int,int,int>>pq;

        for(int i = 0 ; i<value.size() ; i++) pq.push({value[i] , 1 , i});

        int total_gain = 0;

        while(m-- and !pq.empty())
        {
            auto[val , freq , index] = pq.top();
            pq.pop();

            total_gain += val;

            int resultant = (val - decay[index]);

            if(resultant > 0) pq.push({resultant , freq+1 , index});
        }
        return total_gain;
    } 
};