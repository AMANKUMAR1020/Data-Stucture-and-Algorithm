//By ai
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll largestAreaHistogram(ll arr[], int n) {
    int rb[n]; // Next smaller element to the right
    int lb[n]; // Next smaller element to the left

    stack<int> st;

    // Compute rb[]: index of the next smaller element to the right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        rb[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Clear the stack for the next computation
    while (!st.empty()) st.pop();

    // Compute lb[]: index of the next smaller element to the left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        lb[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Calculate max area
    ll maxArea = 0;
    for (int i = 0; i < n; i++) {
        ll width = rb[i] - lb[i] - 1;
        ll area = width * arr[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}



// By sumit 




ll largestAreaHistogram(ll arr[], int n){
    int rb[n]={0};    rb[n-1] = n-1;
    int lb[n]={0};    lb[0] = -1;

    stack<int> st,st2;
    st.push(n-1);

    for(int i=n-2; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        rb[i] = st.size() == 0 ? n : st.top();

        st.push(i);
    }

    st2.push(0);


    for(int i=1; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        rb[i] = st.size() == 0 ? -1 : st.top();

        st.push(i);
    }

    ll maxArea = 0;
    for(int i=0; i<n; i++){
        ll width = rb[i] - lb[i] - 1;
        maxArea = max(width*arr[i], maxArea);
    }

    return maxArea;
}

int main(){
	text();
    int n; cin>>n;
    ll arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<largestAreaHistogram(arr, n)<<endl;
}

