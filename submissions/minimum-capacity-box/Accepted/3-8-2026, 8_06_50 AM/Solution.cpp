// https://leetcode.com/problems/minimum-capacity-box

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mini = INT_MAX;
        int index = -1;
        
        for(int i = 0 ; i<capacity.size() ; i++){
            if(capacity[i] >= itemSize and capacity[i] < mini){
                mini = capacity[i];
                index = i;
            }
        }
    return index;
    }
};