// class Solution {
//   public:
  
//     int prec(char c){
//         if(c == '^')
//             return 3;
            
//         else if(c == '/' || c == '*')
//             return 2;
            
//         else if(c == '+' || c == '-')
//             return 1;
            
//         else
//             return -1;
//     }
    
//     bool isRightAssociative(char c) {
//         return c == '^';
//     }
    
//     string infixToPostfix(string& s) {
//         stack<char> st;
//         string res = "";
        
//         for(char c : s){
//             if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')){
//                 res += c;
                
//             }else if(c == '('){
//                 st.push(c);
                
//             }else if(c == ')'){
//                 while(!st.empty() && st.top() !=  '('){
//                     res += st.top();    st.pop();
//                 }
//             }else{
//                 while(!st.empty() && st.top() != '('){
//                     char t = st.top();
                    
//                     if(prec(t) > prec(c) || (prec(t) == prec(c) && !isRightAssociative(c))){
//                         res += t;
//                         st.pop();
//                     }else 
//                         break;
//                 }
//             }
//         }
        
//         while(!st.empty()){
//             if(st.top() != '(')
//                 res += st.top();    st.pop();
//         }
//         return res;
//     }
// };



class Solution {
public:
    int prec(char c){
        if(c == '^') return 3;
        if(c == '/' || c == '*') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }

    bool isRightAssociative(char c) {
        return c == '^';
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string res;

        for(char c : s){
            if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')){
                res += c;
            } 
            else if(c == '('){
                st.push(c);
            } 
            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    res += st.top();
                    st.pop();
                }
                if(!st.empty() && st.top() == '(') st.pop();
            } 
            else { // operator
                while(!st.empty() && st.top() != '('){
                    char t = st.top();
                    if(prec(t) > prec(c) || (prec(t) == prec(c) && !isRightAssociative(c))){
                        res += t;
                        st.pop();
                    } else break;
                }
                st.push(c);
            }
        }

        while(!st.empty()){
            if(st.top() != '(') res += st.top();
            st.pop();
        }
        return res;
    }
};




