// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    unordered_map<int,int> mp;

    RandomizedSet() {}

    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val] = 1;
        return true;
    }

    bool remove(int val) {
        if(!mp.count(val)) return false;
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int k = rand() % mp.size();

        auto it = mp.begin();
        advance(it, k);

        return it->first;
    }
};