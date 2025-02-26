class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool neg=0;
        int i=0;
        while (s[i]==' '){
            i++;
        }
        if (s[i]=='-'|| s[i]=='+'){
            if (s[i]=='-')neg=1;
            i++;
        }
        for (; i<s.size(); i++){
            if (s[i]>='0' && s[i]<='9'){
                if (!neg && ans>=(pow(2,31)-1)){ans= pow(2,31)-1; break;}
                if (neg && ans>(pow(2,31))){ans= -1* pow(2,31); break;}
                ans*=10;
                ans+= (s[i]-'0');
            }
            else break;
        }
        if (neg && ans>0)ans*= -1;
        if (ans>=(pow(2,31)-1))ans= pow(2,31)-1;
        if (ans<=(-1*pow(2,31)))ans= -1* pow(2,31);
        
        return ans;

/*
class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        bool sign=false;
        bool started = false;

        for(char c : s){
            if(c == ' '){
                if(started)break;
                continue;
            }

            else if(c == '-'){
                if(started)break;
                sign = true;

            }else if(c>='0' && c<='9'){
                started = true;
                long long temp = ans * 10 + (c - '0');

                if (temp > INT_MAX) {
                    return sign ? INT_MAX : INT_MIN;
                }
                ans = temp;
                //cout<<ans<<endl;
            }else{
                break;
            }
        }
        return sign ? -ans : ans;
    }
};
*/
