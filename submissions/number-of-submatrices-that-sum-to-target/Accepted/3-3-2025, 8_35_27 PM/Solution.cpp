// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
     int n = matrix.size(), m = matrix[0].size();
    int count = 0;

    // Compute prefix sums for each column
    vector<vector<int>> prefix(n+1, vector<int>(m, 0));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            prefix[i+1][j] = prefix[i][j] + matrix[i][j];

    // Iterate over all row pairs (r1, r2)
    for (int r1 = 0; r1 < n; r1++) {
        for (int r2 = r1; r2 < n; r2++) {
            unordered_map<int, int> prefixSumCount;
            prefixSumCount[0] = 1; // Base case for exact match
            
            int curSum = 0;
            for (int j = 0; j < m; j++) {
                // Compute column sum for this row range
                curSum += prefix[r2+1][j] - prefix[r1][j];

                // Check if (curSum - target) exists in the map
                if (prefixSumCount.find(curSum - target) != prefixSumCount.end()) {
                    count += prefixSumCount[curSum - target];
                }

                // Update hashmap
                prefixSumCount[curSum]++;
            }
        }
    }

    return count;   
    }
};