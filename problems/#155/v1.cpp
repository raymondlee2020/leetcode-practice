class MinStack {
public:
    vector<pair<int, int>> ctr;

    MinStack() {
        
    }
    
    void push(int val) {
        if (ctr.size() == 0) {
            ctr.push_back({val, val});
        } else {
            ctr.push_back({val, min(val, ctr.back().second)});
        }
    }
    
    void pop() {
        ctr.pop_back();
    }
    
    int top() {
        return ctr.back().first;
    }
    
    int getMin() {
        return ctr.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */