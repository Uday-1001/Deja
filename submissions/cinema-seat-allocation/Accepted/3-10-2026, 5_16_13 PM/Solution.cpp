// https://leetcode.com/problems/cinema-seat-allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , vector<int>>seats;

        for(auto it : reservedSeats)
        {
            int row = it[0];
            int seat_col = it[1];
            seats[row].push_back(seat_col);
        }

        int ans = 0;
        if(seats.size() != n) ans += ((n - seats.size()) * 2);

        for(auto &it : seats)
        {
            bool areseated = false;
            unordered_set<int>st;
            for(auto seat : it.second) st.insert(seat);

            if(!st.count(2) and !st.count(3) and !st.count(4) and !st.count(5)) 
            {
                ans++; 
                areseated = true;
            }
            if(!st.count(6) and !st.count(7) and !st.count(8) and !st.count(9)) 
            {
                ans++;
                areseated = true;
            }
            if(!st.count(4) and !st.count(5) and !st.count(6) and !st.count(7) and areseated == false) ans++;

        }
    return ans;
    }
};