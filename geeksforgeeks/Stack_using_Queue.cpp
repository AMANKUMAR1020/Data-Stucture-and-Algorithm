class myStack {
    queue<int> q;
    queue<int> tq;

  public:

    void push(int x) {
        q.push(x);
    }

    void pop() {

        while(q.size() > 1){
            tq.push(q.front()); q.pop();
        }
        
        if(!q.empty())
            q.pop();
        
        while(!tq.empty()){
            q.push(tq.front()); tq.pop();
        }
    }

    int top() {
        return q.empty() ? -1 : q.back();
    }

    int size() {
        return q.empty() ? 0 : q.size();
    }
};
