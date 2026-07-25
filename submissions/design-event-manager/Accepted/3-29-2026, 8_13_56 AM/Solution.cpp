// https://leetcode.com/problems/design-event-manager

class EventManager {
public:
    unordered_map<int,int>mp;
    set<pair<int,int>>st;
    EventManager(vector<vector<int>>& events) {
        for(auto it : events){
            int id = it[0];
            int prio = it[1];
            mp[id] = prio;
            st.insert({-prio , id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldprio = mp[eventId];
        st.erase({-oldprio , eventId});
        mp[eventId] = newPriority;
        st.insert({-newPriority , eventId});
    }
    
    int pollHighest() {
        if(st.empty()) return -1;
        auto first = st.begin();
        int id = first->second;
        st.erase(first);
        mp.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */