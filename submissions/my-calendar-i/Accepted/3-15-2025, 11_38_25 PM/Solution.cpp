// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) 
    {
        pair<int,int>Pair = make_pair(startTime , endTime);
        auto it = st.lower_bound(Pair);
        if(it != st.end())
        {
            if(it->first < endTime)
            return false;
        }
        if(it != st.begin())
        {
            auto it2 = prev(it); 
        if(it2->second > startTime)
            return false;
        }
        st.insert(Pair);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */