class Solution {
public:
    string smallestNumber(string s) {
        int n = s.size();
        stack<int> st;
        string result = "";        

        for(int i=0; i<=n; i++){
            st.push(i+1);

            if(i == n || s[i] == 'I'){
                while(!st.empty()){
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};

/*
string ans="";

class Solution {

public:
    string smallestNumber(string pattern) {
        string str="";
        unordered_map<char, bool> mp;
        res(pattern,str,ans,pattern.size(),mp);
        return ans;
    }

private:
    void res(string &pattern, string str,string ans, int n,unordered_map<char, bool> &mp){
        if(str.size() == n){
            ans=str;
            return;
        }
        if(str.size() > 0){
            if(mp[str.back()])return;
            mp[str.back()] = true;
        }

        for(char i='1'; i<='9'; i++){
            if(!str.empty() && mp[i])
                continue;

            str.push_back(i);
            res(pattern, str,ans,n,mp);
            mp[i]=false;
            str.pop_back();
        }
    }
};

*/
