// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        vector<int> v;

        int maxi = INT_MIN;
        int count = 1;
        int start = 0;
        int upper = nums[0] + k;
        for(int i = 1; i<nums.size(); i++){
            int lower = nums[i];
            if(upper >= lower){
                count++;
            }
            else{
                if(maxi < count){
                    v.clear();
                    maxi = count;
                    v.push_back(start);
                    start = i;
                    upper = nums[i] + k;
                }
                else if(maxi == count){
                    v.push_back(start);
                    start = i;
                }
                count = 1;
                upper = nums[i] + k;
            }
        }
        if(maxi < count){
            v.clear();
            maxi = count;
            v.push_back(start);
        }
        else if(maxi == count){
            v.push_back(start);
        }
        cout << "maxi = " << maxi << endl;

        int nano = -1;
        for(auto& x : v){
            cout << x << endl;
            int start = x;
            unordered_map<int, int> freq;
            for(int i = 0; i<maxi; i++){
                freq[nums[start]]++;
                start++;
            }
            int maxfreq = 0;
            for(auto it : freq){
                maxfreq = max(maxfreq, it.second);
            }
            nano = max(nano, maxfreq);
        }
        
        int nonsame = maxi - nano;
        if(numOperations <= nonsame){
            return nano + numOperations;
        }
        if(maxi == 1){
            int second_maxi = INT_MIN;
            int count = 1;
            int upper = nums[0] + k;
            for(int i = 1; i<nums.size(); i++){
                int lower = nums[i] - k;
                if(upper >= lower){
                    count++;
                }
                else{
                    second_maxi = max(second_maxi, count); 
                    count = 1;
                    upper = nums[i] + k;
                }
            }
            second_maxi = max(second_maxi, count); 
            if(second_maxi > numOperations){
                return numOperations;
            }
            return second_maxi;
        }
        return maxi;
        // return maxi + (numOperations - nonsame);
    }
};