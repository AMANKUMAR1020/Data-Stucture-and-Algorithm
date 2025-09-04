// This question is same as "768. Max Chunks To Make Sorted II"

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int srtPrifix = 0;
        int prifix = 0, chunks = 0;
        int n = arr.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(st.empty() || st.top() < arr[i])
                st.push(arr[i]);
            else{
                int temp = st.top();
                while(!st.empty() && arr[i] < st.top()){st.pop();}
                st.push(temp);
            }
        }
        return st.size();
    }
};

