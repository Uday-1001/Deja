// https://leetcode.com/problems/corporate-flight-bookings

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>booked(n,0);

        for(int i =0 ; i<bookings.size() ; i++)
        {
            int start = bookings[i][0]-1;
            int end = bookings[i][1]-1;
            int seats = bookings[i][2];

            booked[start] += seats;
            if(end+1 < booked.size())
            {
                booked[end+1] -= seats;
            }
        }

        for(int i = 1 ; i<booked.size(); i++)
        {
            booked[i] = booked[i] + booked[i-1];
        }
        return booked;
    }
};