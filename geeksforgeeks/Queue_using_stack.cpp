class myQueue {
  stack<int> ms;
  stack<int> ts;
  int frontNum;
  public:
    myQueue() {
        frontNum = -1;
    }

    void enqueue(int x) {
        if(ms.empty())
            frontNum = x;
        ms.push(x);
    }

    void dequeue() {
        while(!ms.empty()){
            ts.push(ms.top()); ms.pop();
        }
        
        if(!ts.empty())
            ts.pop();
            
        if(ts.empty()){
            frontNum = -1;
        }else{
            bool flag = true;
            while(!ts.empty()){
                if(flag){
                    frontNum = ts.top();
                    flag = false;
                }
                ms.push(ts.top()); ts.pop();
            }
        }
    }

    int front() {
        return frontNum;
    }

    int size() {
        return ms.size();
    }
};
