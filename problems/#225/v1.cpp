class MyStack {
public:
    queue<int> curr;
    queue<int> alt;

    MyStack() {
        
    }
    
    void push(int x) {
        curr.push(x);
    }
    
    int pop() {
        while (curr.size() > 1) {
            alt.push(curr.front());
            curr.pop();
        }
        int ret = curr.front();
        curr.pop();
        swap(curr, alt);
        return ret;
    }
    
    int top() {
        return curr.back();
    }
    
    bool empty() {
        return curr.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */