class MinStack {
    stack<int> main;
    stack<int> mini;
public:
    MinStack() {}
    
    void push(int val) {
        main.push(val);

        stack<int> temp;
        while(!mini.empty() && mini.top() < val){
            temp.push(mini.top()); mini.pop();
        }
        mini.push(val);
        while(!temp.empty()){
            mini.push(temp.top()); temp.pop();
        }        
    }
    
    void pop() {
        int tp = main.top(); main.pop();

        stack<int> temp;
        while(!mini.empty() && mini.top() != tp){
            temp.push(mini.top()); mini.pop();
        }
        mini.pop();
        while(!temp.empty()){
            mini.push(temp.top()); temp.pop();
        }
    }
    
    int top() {
        return !main.empty() ? main.top() : -1;
    }
    
    int getMin() {
        return !mini.empty() ? mini.top() : -1;
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
