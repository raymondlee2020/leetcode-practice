class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        lru.splice(lru.begin(), lru, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            lru.splice(lru.begin(), lru, it->second);
            it->second->second = value;
            return;
        }
        if (cache.size() == cap) {
            cache.erase(lru.back().first);
            lru.pop_back();
        }
        lru.emplace_front(key, value);
        cache[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */