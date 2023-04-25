class SmallestInfiniteSet {
public:
    vector<bool> nums;
    int smallest;

    SmallestInfiniteSet() {
        nums = vector<bool>(1001, true);
        nums[0] = true;
        smallest = 1;
    }
    
    int popSmallest() {
        int ret = smallest;
        nums[ret] = false;
        while (!nums[++smallest]) {}
        return ret;
    }
    
    void addBack(int num) {
        if (nums[num]) {
            return;
        }
        nums[num] = true;
        smallest = min(smallest, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */