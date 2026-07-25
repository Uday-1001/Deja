// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime){
        int maxi = INT_MIN;
        mp[startTime] ++;
        mp[endTime] --;
        int count = 0;

        for(auto &it : mp)
        {
            count += it.second;
            maxi = max(maxi , count);
        }
        return maxi;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */