class LRUCache {
private:
    int cap;
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        
        auto it = mp[key];
        int val = it->second;
        lst.erase(it);
        lst.push_front({key, val});
        mp[key] = lst.begin();

        return val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lst.erase(mp[key]);
        } else if (lst.size() == cap) {
            int oldKey = lst.back().first;
            lst.pop_back();
            mp.erase(oldKey);
        }
        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */