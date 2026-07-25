// https://leetcode.com/problems/my-calendar-ii

class MyCalendarTwo {
public:
    map<int,int>mapping;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int maxi = INT_MIN;
        mapping[startTime]++;
        mapping[endTime]--;
        int count = 0;

        for(auto it :mapping)
        {
            count += it.second;
            maxi = max(maxi , count);
            if(maxi >= 3)
            {
                mapping[startTime]--;
                mapping[endTime]++;
                return false;
            }
        }
    return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */