// https://leetcode.com/problems/elimination-game

class Solution {
public:
    void byrec(vector<int>& vec, int& ans, bool isLeft) {
        int n = vec.size();
        
        // Base case: Only one element remains
        if (n == 1) {
            ans = vec[0];
            return;
        }

        vector<int>new_vec;

        if(isLeft == true) 
        {
            for(int i = 1; i < n; i += 2) 
            {
                new_vec.push_back(vec[i]);
            }
        } 
        else 
        {
            int start_index = (n % 2 == 0) ? 0 : 1;
            
            for(int i = start_index; i < n; i += 2) 
            {
                new_vec.push_back(vec[i]);
            }
        }
        //call with the new vector and the opposite direction
        byrec(new_vec, ans, !isLeft);
    }
    
    int lastRemaining(int n) {
        if (n == 1) return 1;

        vector<int>vec;
        for(int i = 1; i <= n; i++) vec.push_back(i);

        int ans = 0;
        byrec(vec, ans, true);
        return ans;
    }
};