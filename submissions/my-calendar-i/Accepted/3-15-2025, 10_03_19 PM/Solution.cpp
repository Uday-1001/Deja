// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    vector<pair<int,int>>vp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
    
    for(int i =0 ; i<vp.size() ; i++)
    {
        auto lastPair = vp[i];
        if(lastPair.second > startTime and lastPair.first < endTime)
            return false;
    }
    vp.push_back({startTime,endTime});
    return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */