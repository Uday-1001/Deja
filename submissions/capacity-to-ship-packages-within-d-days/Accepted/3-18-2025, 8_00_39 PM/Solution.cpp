// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool ispossible(vector<int>& weights, int days ,int mid)
    {
        int sum = 0;
        int curr_day = 1;
        for(int i =0; i<weights.size(); i++)
        {
            if(weights[i] > mid){
                return false;
            }
            else if(sum + weights[i] > mid)
            {
                sum = weights[i];
                curr_day++;
                // sum = 0;
            }
            else{
                sum += weights[i];
            }
        }
        cout << curr_day << endl;
        return curr_day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *min_element(weights.begin() , weights.end());
        int e = accumulate(weights.begin() , weights.end() ,0);
        int ans = -1;

        while(s<=e)
        {
            int mid  = s+(e-s)/2;
            if(ispossible(weights,days,mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};