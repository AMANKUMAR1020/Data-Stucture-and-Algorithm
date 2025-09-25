
/*
    class Solution {
    public:
        int lastRemaining(int n) {
            stack<int> st1;
            stack<int> st2;
            for(int i=n; i>0; i--)
                st1.push(i);
    
            return solve(st1);
        }
        int solve(stack<int> st1){
            if(st1.size() == 1)
                return st1.top();
    
            int i=1;
            stack<int> st2;
            while(!st1.empty()){
                int temp = st1.top(); st1.pop();
                if(i%2==0){
                    st2.push(temp);
                }
                i++;
            }
            return solve(st2);
        }
    };
*/

class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool left = true;

        while (remaining > 1) {
            if (left || remaining % 2 == 1) {
                head += step;
            }
            remaining /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
