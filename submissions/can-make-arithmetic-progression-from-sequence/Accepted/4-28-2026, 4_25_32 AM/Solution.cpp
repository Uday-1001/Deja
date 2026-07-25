// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr) , end(arr));
        
        int diff = abs(arr[0] - arr[1]);
        for(int i = 1 ; i+1<arr.size() ; i++)
        {
            if(abs(arr[i] - arr[i+1]) != diff) return false;
        }
        return true;
    }
};