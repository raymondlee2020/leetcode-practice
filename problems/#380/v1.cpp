class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (keys.find(val) != keys.end()) {
            return false;
        }
        vals.push_back(val);
        keys[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (keys.find(val) == keys.end()) {
            return false;
        }
        int n = vals.size();
        keys[vals[n - 1]] = keys[val];
        swap(vals[keys[val]], vals[n - 1]);
        keys.erase(val);
        vals.pop_back();
        return true;
    }
    
    int getRandom() {
        return vals[rand()%(vals.size())];
    }
private:
    vector<int> vals;
    unordered_map<int, int> keys;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */