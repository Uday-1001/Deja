// https://leetcode.com/problems/design-a-number-container-system

class NumberContainers {
public:

    unordered_map<int,int> hash;
    unordered_map<int,set<int>> hash2;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(hash.find(index) == hash.end())
        {
            hash[index] = number;
            hash2[number].insert(index);
        }
        else
        {
            hash2[hash[index]].erase(index);
            hash[index] = number;
            hash2[number].insert(index);
        }
    }
    
    int find(int number) {
        if(hash2.find(number) != hash2.end())
        {
            return *hash2[number].begin();
        }
        else
        {
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */