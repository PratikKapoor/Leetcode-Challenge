class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> minstack;
    int min_stack_ele;
    
    MinStack() {
        min_stack_ele = INT_MAX;
    }
    
    void push(int x) {
        // Keep track of lowest element.
        if (x < min_stack_ele) {
            min_stack_ele = x;
        }
        
        minstack.push(make_pair(x, min_stack_ele));
    }
    
    void pop() {
        if(!minstack.empty()) {
            minstack.pop();
            if(!minstack.empty()) {
                // Smallest element is now the element stored when the current top was pushed.
                min_stack_ele = minstack.top().second;
            } else {
                min_stack_ele = INT_MAX;
            }
        }
    }
    
    int top() {
        return minstack.top().first;
    }
    
    int getMin() {
        return minstack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
