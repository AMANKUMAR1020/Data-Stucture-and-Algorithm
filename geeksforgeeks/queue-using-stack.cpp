//option 1 is best approch in O(n*n)
//option 2 is best approch in O(n)

class myQueue {
    
    stack<int> st,prev;
    
  public:
    myQueue() {
        // Initialize your data members
    }
    
    void addFront(int x){
        stack<int> temp;
        
        while(!st.empty()){
            prev.push(st.top());
            temp.push(st.top());  st.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());  temp.pop();
        }
        
    }
    void enqueue(int x) {
        // Implement enqueue operation
        st.push(x);
        addFront(x);
    }

    void dequeue() {
        // Implement dequeue operation
        
        stack<int> temp;
        
        while(!st.empty()){
            temp.push(st.top());  st.pop();
        }
        temp.pop();
        prev.pop();
        while(!temp.empty()){
            st.push(temp.top());  temp.pop();
        }
        
    }

    int front() {
        // Implement front operation
        return st.empty() ? -1 : prev.top();
    }

    int size() {
        // Implement size operation
        return st.empty() ? 0 : st.size();
    }
};



/*
class MyQueue {
    stack<int> in, out;

    void moveIfNeeded() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

public:
    void enqueue(int x) {
        in.push(x);
    }

    void dequeue() {
        if (in.empty() && out.empty()) return; // or throw
        moveIfNeeded();
        out.pop();
    }

    int front() {
        if (in.empty() && out.empty()) return -1;
        moveIfNeeded();
        return out.top();
    }

    int size() {
        return (int)in.size() + (int)out.size();
    }
};

*/
