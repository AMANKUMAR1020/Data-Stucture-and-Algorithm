class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<bool> visited(n+1,false);
        vector<int> ans;
        for(int i=1; i<= 9; i++){
            if(i<=n)
                dfs(i, n, ans);
        }
        return ans;
    }
 void dfs(int ind, int n, vector<int>& ans){
    if(ind > n)return;
     ans.push_back(ind);

     for(int i=1; i<=9; i++){
         int nxt = ind*10 + i;
         if(nxt > n)
             break;
         dfs(nxt, n, ans);
     }
    }
};


/*
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int dig = log10(n)+1;
        vector<int> vec1;
        vector<string> vec2;
        for(int i=1; i<=n;i++){
            string str = to_string(i);
            vec2.push_back(str);
        }
        sort(vec2.begin(), vec2.end());
        for(int i=0; i<n;i++){
            int num = stoi(vec2[i]);
            vec1.push_back(num);
        }
        return vec1;
    }
};
*/