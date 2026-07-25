// https://leetcode.com/problems/apple-redistribution-into-boxes

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int boxes = 0;
        sort(capacity.rbegin() , capacity.rend());
        int sum = accumulate(apple.begin() , apple.end() , 0);

        for(auto n : capacity)
        {
            if(sum <= 0) break;
            sum -= n;
            boxes++;
        }
    return boxes;
    }
};