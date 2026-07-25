// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    int cap;
    list<pair<int,int>>dll;
    unordered_map<int , list<pair<int,int>>::iterator>mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        auto it = mp[key];
        int value = it->second;

        dll.erase(it);
        dll.push_back({key , value});
        mp[key] = prev(dll.end());

        return value;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            dll.erase(mp[key]);
        }
        else 
        {
            if(dll.size() == cap)
            {
                auto leastused = dll.begin();
                mp.erase(leastused->first);
                dll.pop_front();
            }
        }
        dll.push_back({key , value});
        mp[key] = prev(dll.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */