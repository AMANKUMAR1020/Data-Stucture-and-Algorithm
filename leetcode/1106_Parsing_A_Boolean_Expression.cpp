class Solution {

char ind = 0;
public:
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        
        bool flag,ok=false;
        stack<char> st;
        while(i < n){         
            if(exp[i] =='f' || exp[i] =='t'){
                ind = check(st.top(),exp[i]);

            }else if(exp[i] =='&' || exp[i] =='|' || exp[i] =='!'){
                st.push(exp[i]);
            }else if(exp[i] ==')'){
                st.pop();
                if(!st.empty()){
                    ind = check(ind,st.top());
                }
            }
        }
        return ind;        
    }
    private:
    bool cheack(char syb,char c){
        if(syb == '|'){ c=='f' ? ans = }
    } 
};
