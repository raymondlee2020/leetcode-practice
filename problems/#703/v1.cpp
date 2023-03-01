class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums.size() <= k) {
            q = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        } else {
            q = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.begin() + k);
        }
    }
    
    int add(int val) {
        if (q.size() < k) {
            q.push(val);
        } else if (val > q.top()) {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */