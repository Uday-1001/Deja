// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    vector<pair<int,int>>vp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
    if(vp.size() == 0)
    {
        vp.push_back({startTime,endTime});
    }
    else
    for(int i =0 ; i<vp.size() ; i++)
    {
        auto lastPair = vp[i];
        if(lastPair.second > startTime)
            return false;
    }
    return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */