class Solution {
  public:
    int romanToDecimal(string &s) {
        stack<int> st;
        int n = s.size();
        int temp = 0;
        for(int i=n-1; i>=0; i--){
            char c = s[i];
            temp = num(c);
            if(st.empty()){
                st.push(temp);
            }else if(temp < st.top()){
                st.top() -= temp;
            }else{
                st.push(temp);
            }
            //cout<<st.top()<<endl;
        }
        
        int sum = 0;
        while(!st.empty()){
            sum += st.top(); st.pop();
        }
        return sum;
    }
    
    int num(char c){
        if('M' == c){
            return 1000;
        }else if('D' == c){
            return 500;
        }else if('C' == c){
            return 100;
        }else if('L' == c){
            return 50;
        }else if('X' == c){
            return 10;
        }else if('V' == c){
            return 5;
        }else{
            return 1;
        }
    }
    
};
