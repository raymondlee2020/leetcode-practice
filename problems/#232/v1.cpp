class MyQueue {
public:
    stack<int> main;
    stack<int> tmp;

    MyQueue() {
        
    }
    
    void push(int x) {
        while (!main.empty()) {
            tmp.push(main.top());
            main.pop();
        }
        main.push(x);
        while (!tmp.empty()) {
            main.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        int ret = main.top();
        main.pop();
        return ret;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */