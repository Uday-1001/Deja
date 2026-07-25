// https://leetcode.com/problems/split-and-merge-array-transformation

class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
        
        // If nums1 is already equal to nums2, 0 operations are needed.
        if (nums1 == nums2) {
            return 0;
        }

        // The queue stores pairs of {current_permutation, distance}.
        std::queue<std::pair<std::vector<int>, int>> q;
        // The visited set stores permutations we have already processed.
        std::set<std::vector<int>> visited;

        q.push({nums1, 0});
        visited.insert(nums1);

        while (!q.empty()) {
            std::pair<std::vector<int>, int> current_state = q.front();
            q.pop();

            std::vector<int> current_perm = current_state.first;
            int dist = current_state.second;

            // Generate all possible next states from the current permutation.
            
            // 1. Choose the start (L) and end (R) of the subarray to split.
            for (int L = 0; L < n; ++L) {
                for (int R = L; R < n; ++R) {
                    
                    // Extract the subarray and the remaining elements.
                    std::vector<int> subarray(current_perm.begin() + L, current_perm.begin() + R + 1);
                    
                    std::vector<int> remaining_array;
                    remaining_array.insert(remaining_array.end(), current_perm.begin(), current_perm.begin() + L);
                    remaining_array.insert(remaining_array.end(), current_perm.begin() + R + 1, current_perm.end());

                    // 2. Try inserting the subarray at every possible position (P).
                    for (int P = 0; P <= remaining_array.size(); ++P) {
                        std::vector<int> new_perm = remaining_array;
                        new_perm.insert(new_perm.begin() + P, subarray.begin(), subarray.end());

                        // If the new permutation matches the target, we've found the shortest path.
                        if (new_perm == nums2) {
                            return dist + 1;
                        }
                        
                        // If we haven't seen this permutation before, add it to the queue and visited set.
                        if (visited.find(new_perm) == visited.end()) {
                            visited.insert(new_perm);
                            q.push({new_perm, dist + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};