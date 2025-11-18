
class Solution {
  public:
    string postToPre(string post_exp) {
        string str = postToNor(post_exp);
        //cout<<str<<endl;
        return norToPre(str);
    }
    string postToNor(string exp){
        stack<string> st;

        for(char c : exp){
            if(c == '*' || c == '/' || c == '+' || c == '-'){
                string tp1 = st.top(); st.pop();
                string tp2 = st.top(); st.pop();
                string nstr = "";
                nstr = "(" + tp1 + c + tp2 + ")";
                st.push(nstr);
            }else{
                string temp = ""; temp += c;
                st.push(temp);    
            }
        }
        return st.top();
    }
    
    string norToPre(string exp){
        stack<string> st;

        for(char c : exp){
            if(c == ')'){
                string tp1 = st.top(); st.pop();
                string tp2 = st.top(); st.pop();
                string tp3 = st.top(); st.pop();
                st.pop();
                
                string nstr = "";
                nstr = tp2 + tp1 + tp3;
                st.push(nstr);
            }else{
                string temp = ""; temp += c;
                st.push(temp);    
            }
        }
        return st.top();
  
    }
};
