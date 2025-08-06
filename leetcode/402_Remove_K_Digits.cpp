class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(char c : num){
            while(k && (!st.empty() && st.back() > c)){
                k--;
                st.pop_back();
            }
            st.push_back(c);            
        }
        while(k && !st.empty()){
            st.pop_back();   k--;
        }

        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        return st.empty() ? "0" : st;
    }
};
