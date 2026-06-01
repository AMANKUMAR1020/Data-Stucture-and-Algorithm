// #include<bits/stdc++.h>
// #include<iostream>

// #define ONLINE_JUDGE

// using namespace std;
// using ll = long long int;

// void text(){
// 	#ifdef ONLINE_JUDGE
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif
// }


// void minimumStack(stack<ll>& st){
// 	ll minSt = 0;
// 	vector<ll> vec{8,47,17,7,30,2};

// 	for(ll v : vec){
// 		if(!st.empty() && st.top() <= minSt){
// 			minSt = v;
// 			st.push(v + v - minSt);			
// 		}else{
// 			if(minSt == 0)
// 				minSt = v;
// 			st.push(v);
// 		}
// 	}
// 	while(!st.empty()){
// 		if(st.top() < minSt){
// 			cout<<minSt<<" ";
// 			minSt = 2*minSt - st.top();
// 		}else{
// 			cout<<st.top()<<" ";			
// 		}
// 		st.pop();
// 	}
// }

// int main(){
// 	text();
// 	stack<ll> st;
// 	minimumStack(st);
// 	return 0;
// }





#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

void text() {
#ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void minimumStack(stack<ll>& st) {
    ll minSt = LLONG_MAX;   // Start with very large number
    vector<ll> vec{8,47,17,7,30,2};

    // Push logic
    for (ll v : vec) {
        if (st.empty()) {
            st.push(v);
            minSt = v;
        } else if (v >= minSt) {
            st.push(v);
        } else {
            // encode value
            st.push(2*v - minSt);
            minSt = v;
        }
    }

    // Pop logic
    while (!st.empty()) {
        ll topVal = st.top();
        st.pop();

        if (topVal >= minSt) {
            cout << topVal << " ";
        } else {
            cout << minSt << " ";
            minSt = 2*minSt - topVal;  // restore previous min
        }
    }
    cout << "\n";
}

int main() {
    text();
    stack<ll> st;
    minimumStack(st);
    return 0;
}




