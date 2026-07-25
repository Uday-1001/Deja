// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class Solution {
public:

    int maxlen = 0;

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        if(n < 3) return 0;

        unordered_map<int,int>hashset;
        for(auto num : arr)
        {
            hashset[num]++;
        }

        for(int i = 0 ; i<arr.size() ; i++)
        {
            for(int j = i+1 ; j<arr.size() ; j++)
            {
                int curr = arr[i] + arr[j];
                int prev = arr[j];
                int curr_len = 2;
                
                while(hashset.find(curr) != hashset.end())
                {
                    int temp = curr;
                    curr += prev;
                    prev = temp;

                    curr_len++;
                    maxlen = max(curr_len , maxlen);
                }
            }
        }
    return maxlen;  
    }
};