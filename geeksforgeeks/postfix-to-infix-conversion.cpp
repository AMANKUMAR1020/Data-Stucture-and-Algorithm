class Solution {
  public:
    string postToInfix(string &s) {
        stack<string> st;
        string str = "";
        int n = s.size();
        
        for(int i=0; i<n; i++){
            char c = s[i];
            if(c == '/' || c == '^' || c == '*' || c == '+' || c == '-'){
                string b = st.top(); st.pop();
                string a = st.top(); st.pop();
                st.push('(' + a + c + b + ')');
            }else{
                st.push(string(1, s[i]));
            }
        }
        return st.top();
        
    }
};
