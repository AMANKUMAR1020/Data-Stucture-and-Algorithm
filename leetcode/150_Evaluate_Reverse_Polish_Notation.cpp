class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int num = 0;
                if(s == "+")
                    num = num2 + num1;
                else if(s == "-")
                    num = num2 - num1;
                else if(s == "*")
                    num = num2 * num1;
                else
                    num = num2 / num1;
                st.push(num);
            }else
                st.push(stoi(s));
            
        }
        return st.empty() ? -1 : st.top() ;
    }
};
