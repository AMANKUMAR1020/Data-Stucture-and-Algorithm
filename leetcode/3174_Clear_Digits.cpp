class Solution {
public:
    string clearDigits(string s) {
        string str="";
        
        for(int c : s){
            if(!str.empty() && c >= '0' && c <= '9'){
                str.pop_back();
            }else{
                str+=c;
            }
        }
        return str;
    }
};
