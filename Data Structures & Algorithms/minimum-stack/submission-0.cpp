class MinStack {
public:
    stack<int> elem;
    stack<int> prefix;

    MinStack() {
        this->elem = {};
        this->prefix = {};
    }
    
    void push(int val) {
        elem.push(val);
        prefix.push(prefix.size() == 0 ? val : min(val, prefix.top()));
    }
    
    void pop() {
        elem.pop();
        prefix.pop();
    }
    
    int top() {
        return elem.top();
    }
    
    int getMin() {
        return prefix.top();
    }
};
