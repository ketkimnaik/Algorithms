class MyStack {
   deque<int> q;
    int size=0;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
       q.push_front(x);
        ++size;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
       if(q.empty())
           return -1;
        
         int a=q.front();
        --size;
        q.pop_front();
        return a;
        
    }
    
    /** Get the top element. */
    int top() {
        
        if(q.empty())
            return -1;
        
        int a=q.front();
        return a;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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