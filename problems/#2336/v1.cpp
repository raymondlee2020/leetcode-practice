class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, bool> exist;

    SmallestInfiniteSet() {
        vector<int> nums(1000, 0);
        for (int i = 0; i < 1000; ++i) {
            nums[i] = i + 1;
            exist[i + 1] = true;
        }
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
    }
    
    int popSmallest() {
        int ret = pq.top();
        pq.pop();
        exist[ret] = false;
        return ret;
    }
    
    void addBack(int num) {
        if (exist[num]) {
            return;
        }
        pq.push(num);
        exist[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */