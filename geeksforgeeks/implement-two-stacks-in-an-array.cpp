class twoStacks {
    int p1 = 0;
    int p2 = 0;
    int mid = 0;
    vector<int> vec;
  public:

    twoStacks() {
        int n = 1000;
        mid = n/2;
        vec.resize(n);
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(p1 >= mid)   return;
        vec[p1++] = x;
    }
    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        int m = vec.size() - mid;
        if(p2 >= mid)   return;
        
        vec[mid + p2++] = x;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        return p1 == 0 ? -1 : vec[--p1];
    }
        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        return p2 == 0 ? -1 : vec[mid+ --p2];
    }
};

