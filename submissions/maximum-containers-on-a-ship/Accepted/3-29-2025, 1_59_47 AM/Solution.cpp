// https://leetcode.com/problems/maximum-containers-on-a-ship

class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int containers = maxWeight / w;

        return min(n*n , containers);
    }
};