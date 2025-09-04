// this question is same as "7769. Max Chunks To Make Sorted"
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0, n = arr.size();
		stack<int> st;
		for(int i=0; i<n; i++){
			if(st.empty() || st.top() < arr[i]){
				st.push(arr[i]);
			}else{
				int temp = st.top();
				while(!st.empty() && arr[i] < st.top()){
					st.pop();
				}
				st.push(temp);
			}
		}
		
		return st.size();

    }
};
