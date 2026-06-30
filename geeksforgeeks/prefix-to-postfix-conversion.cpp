    string preToPost(string &s) {
        stack<string> st;
        string str = "";
        int n = s.size();
        
        for(int i=n-1; i>=0; i--){
            char c = s[i];
            if(c == '/' || c == '^' || c == '*' || c == '+' || c == '-'){
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                st.push(a + b + c);
            }else{
                st.push(string(1, s[i]));
            }
        }
        return st.top();
    }
};
