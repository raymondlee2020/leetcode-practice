class TimeMap {
public:
    map<string, map<int, string>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        auto it = keyTimeMap[key].upper_bound(timestamp);
        if (it == keyTimeMap[key].begin()) {
            return "";
        }
        return prev(it)->second;
    }
};