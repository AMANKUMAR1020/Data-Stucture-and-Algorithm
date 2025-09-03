class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> vec(n,0);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temp[st.top()] <= temp[i]){
                st.pop();
            }
            if(!st.empty()){
                vec[i] = st.top() - i;
            }
            st.push(i);
        }
        return vec;
    }
};

// 0, 1, 2, 3, 4, 5, 6, 7
// 73,74,75,71,69,72,76,73
// st = 7,4,3,2,
// 73 > 49 > 71 > 75 >,
// vec=0,0,0,2,1,1,0,0

