// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxheap;  
        int fuel = startFuel;
        int stops = 0;
        int i = 0; 

        while(fuel < target) 
        {
            // add all the stations reachable with current fuel capacity
            while(i < stations.size() && stations[i][0] <= fuel) 
            {
                maxheap.push(stations[i][1]); 
                i++;
            }

            //if there is no refueling station 
            if(maxheap.empty()) return -1;

            //Refuel from the current station 
            fuel += maxheap.top();
            maxheap.pop();
            stops++;
        }

        return stops;
    }
};
