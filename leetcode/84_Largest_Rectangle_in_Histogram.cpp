class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        int n = height.size();
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : height[i];
            while (!st.empty() && height[st.top()] > h) {
                int heightTop = height[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, heightTop * width);
            }
            st.push(i);
        }
        return ans;
    }
};
